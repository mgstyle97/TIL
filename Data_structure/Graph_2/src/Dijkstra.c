#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF 1000000     // 무한대 (연결이 없는 경우)

typedef struct _GraphType{
    int n;
    int wegiht[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];     // 시작정점으로부터의 최단경로 거리
int found[MAX_VERTICES];        // 방문한 정점 표시

int choose(int n)
{
    int min, minpos;
    min = INT_MAX;
    minpos = -1;
    for(int i = 0; i < n; i++)
        if(distance[i] < min && !found[i]){
            min = distance[i];
            minpos = i;
        }
    found[minpos] = 1;
    return minpos;
}

void print_status(GraphType *g)
{
    static int step = 1;        // 정적 변수 : 지역 변수와 전역 변수의 성질을 모두 가지고 있음
    printf("STEP %d: ", step++);
    printf("distance: ");
    for(int i = 0; i < g->n; i++){
        if(distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf(" found: ");
    for(int i = 0; i < g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

void shortest_path(GraphType *g, int start)
{
    int u, w;
    for(int i = 0; i < g->n; i++){      // 초기화
        distance[i] = g->wegiht[start][i];
        found[i] = 0;
    }
    found[start] = 1;   // 시작 정점 방문 표시
    distance[start] = 0;
    for(int i = 0; i < g->n; i++){
        print_status(g);
        u = choose(g->n);
        for(w = 0; w < g->n; w++)
            if(!found[w])
                if(distance[u] + g->wegiht[u][w] < distance[w])
                    distance[w] = distance[u] + g->wegiht[u][w];
    }
}

int main()
{
    GraphType g = {7,
                    {{0, 7, INF, INF, 3, 10, INF},
                     {7, 0, 4, 10, 2, 6, INF},
                     {INF, 4, 0, 2, INF, INF, INF},
                     {INF, 10, 2, 0, 11, 9, 4},
                     {3, 2, INF, 11, 0, INF, 5},
                     {10, 6, INF, 9, INF, 0, INF},
                     {INF, INF, INF, 4, 5, INF, 0}}
    };
    shortest_path(&g, 0);
}
