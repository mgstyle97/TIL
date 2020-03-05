#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 100

typedef struct _Edge{
    int weight, start, end;
} Edge;
typedef struct _GraphType{
    int n;      // ������ ����
    Edge edges[2 * MAX_VERTICES];
} GraphType;

int parent[MAX_VERTICES];   // �θ� ���

// �ʱ�ȭ
void set_init(int n)
{
    for(int i = 0; i < n; i++)
        parent[i] = -1;
}

// curr�� ���ϴ� ������ ��ȯ�Ѵ�.
int set_find(int curr)
{
    if(parent[curr] == -1)
        return curr;        // ��Ʈ
    while(parent[curr] != -1)
        curr = parent[curr];
    return curr;
}

// �ΰ��� ���Ұ� ���� ������ ��ģ��.
void set_union(int a, int b)
{
    int root1 = set_find(a);    // ��� a�� ��Ʈ�� ã�´�.
    int root2 = set_find(b);    // ��� b�� ��Ʈ�� ã�´�.

    if(root1 != root2)          // �ΰ��� ������ ������ ��ģ��.
        parent[root1] = root2;
}

// �׷��� �ʱ�ȭ
void graph_init(GraphType *g)
{
    g->n = 0;
    for(int i = 0; i < 2 * MAX_VERTICES; i++){
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

// ���� ���� ����
void insert_edge(GraphType *g, int start, int end, int weight)
{
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = weight;
    g->n++;
}

// qsort()�� ���Ǵ� �Լ�
int compare(const void *a, const void *b)
{
    Edge *x = (Edge *)a;
    Edge *y = (Edge *)b;
    return (x->weight - y->weight);
}

// kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(GraphType *g)
{
    int edge_accepted = 0;  // ������� ���õ� ������ ��
    int uset, vset;         // ���� u�� ���� v�� ���� ��ȣ
    int i = 0;
    Edge e;

    set_init(g->n);     // ���� �ʱ�ȭ
    qsort(g->edges, g->n, sizeof(Edge), compare);

    printf("ũ�罺Į �ּ� ���� Ʈ�� �˰��� \n");

    while(edge_accepted < (g->n-1)){    // ������ �� < (n-1)

        e = g->edges[i];
        uset = set_find(e.start);   // ���� u�� ���� ��ȣ
        vset = set_find(e.end);     // ���� v�� ���� ��ȣ

        if(uset != vset){           // ���� ���� ������ �ٸ���    ����Ŭ�� ����
            printf("���� (%d %d) %d ����\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);  // �� ���� ������ ��ģ��.
        }
        i++;
    }
}

int main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);

    kruskal(g);
    free(g);
}