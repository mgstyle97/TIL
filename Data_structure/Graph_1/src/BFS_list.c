#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50

typedef int element;
typedef struct _QueueType{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

typedef struct _GraphNode{
    int vertex;
    struct _GraphNode *link;
} GraphNode;
typedef struct _GraphType{
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void error(char *message)
{
    fprintf(stderr, "%s", message);
    exit(1);
}

void queue_init(QueueType *q)
{
    q->front = q->rear = 0;
}

void graph_init(GraphType *g)
{
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++)
        g->adj_list[i] = NULL;
}

int is_empty(QueueType *q)
{
    return q->rear == q->front;
}

int is_full(QueueType *q)
{
    return ((q->rear) + 1 % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("Queue overflow");
    q->rear = ((q->rear) + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("Queue is empty");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

void insert_vertex(GraphType *g, int v)
{
    if(g->n + 1 > MAX_VERTICES){
        fprintf(stderr, "Overflow");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "Graph: vertex number error");
        return;
    }
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void bfs_list(GraphType *g, int v)
{
    QueueType *q = (QueueType *)malloc(sizeof(QueueType));
    GraphNode *w;

    queue_init(q);
    visited[v] = 1;
    printf("vertex %d -> ", v);
    enqueue(q, v);
    while(!is_empty(q)){
        v = dequeue(q);
        for(w = g->adj_list[v]; w; w = w->link)
            if(visited[w->vertex] != 1){
                visited[w->vertex] = 1;
                printf("vertex %d -> ", w->vertex);
                enqueue(q, w->vertex);
            }
    }
}

int main()
{
    GraphType *g = (GraphType *)malloc(sizeof(GraphType));

    graph_init(g);
    for(int i = 0; i < 6; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    insert_edge(g, 2, 5);
    insert_edge(g, 5, 2);
    insert_edge(g, 1, 5);
    insert_edge(g, 5, 1);
    insert_edge(g, 4, 5);
    insert_edge(g, 5, 4);

    printf("Breath First Search\n");
    bfs_list(g, 0);
    printf("\n");
    free(g);

    return 0;
}
