#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct _GraphNode{
    int vertex;
    struct _GraphNode *link;
} GraphNode;

typedef struct _GraphType{
    int n; //Number of vertex
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES] = {0. };

// Graph init
void init(GraphType *g)
{
    int v;
    g->n = 0;
    for(v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

// Vertex insert operation
void insert_vertex(GraphType *g, int v)
{
    if((g->n) + 1 > MAX_VERTICES){
        fprintf(stderr, "Overflow");
        return;
    }
    g->n++;
}

// edge insert operation
void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node;
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "Graph: vertex number error");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void dfs_list(GraphType *g, int v)
{
    GraphNode *w;
    visited[v] = 1;
    printf("vertex %d -> ", v);
    for(w = g->adj_list[v]; w; w = w->link)
        if(visited[w->vertex] != 1)
            dfs_list(g, w->vertex);
}

int main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i < 4; i++)
        insert_vertex(g, i);

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);


    printf("Depth First Search\n");
    dfs_list(g, 0);
    printf("\n");
    free(g);
    return 0;
}
