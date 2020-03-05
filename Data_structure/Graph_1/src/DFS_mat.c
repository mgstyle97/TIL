#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct _GraphType{
    int n;   // vertex count
    int vertex[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void init(GraphType *g)
{
    g->n = 0;
    for(int i = 0; i < g->n; i++)
        for(int j = 0; j < g->n; j++)
            g->vertex[i][j] = 0;
}

void insert_vertex(GraphType *g, int v)
{
    if((g->n)+1 >= MAX_VERTICES){
        fprintf(stderr, "Overflow");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int start, int end)
{
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "Graph: vertex number error");
        return;
    }
    g->vertex[start][end] = 1;
    g->vertex[end][start] = 1;
}

void dfs_mat(GraphType *g, int v)
{
    visited[v] = 1;
    printf("vertex %d ->", v);

    for(int i = 0; i < g->n; i++){
        if(g->vertex[v][i] && visited[i] != 1)
            dfs_mat(g, i);
    }
}

int main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i < 4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("Depth First Search\n");
    dfs_mat(g, 0);
    printf("\n");

    free(g);
    return 0;
}
