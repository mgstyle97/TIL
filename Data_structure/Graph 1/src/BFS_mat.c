#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

typedef struct _GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
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
        for(int j = 0; j < MAX_VERTICES; j++)
            g->adj_mat[i][j] = 0;
}

int is_empty(QueueType *q)
{
    return q->rear == q->front;
}

int is_full(QueueType *q)
{
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);   
}

void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("Overflow");
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("Queue is empty");
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

void insert_vertex(GraphType *g, int v)
{
    if((g->n)+1 > MAX_VERTICES){
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
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void bfs_mat(GraphType *g, int v)
{
    QueueType *q = (QueueType *)malloc(sizeof(QueueType));

    queue_init(q);
    visited[v] = 1;

    printf("vertex %d -> ", v);
    enqueue(q, v);

    while(!is_empty(q)){
        v = dequeue(q);
        for(int i = 0; i < g->n; i++)
            if(g->adj_mat[v][i] && visited[i] != 1){
                enqueue(q, i);
                visited[i] = 1;
                printf("vertex %d -> ", i);
            }
    }
}

int main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);

    for(int i = 0; i < 6; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);
    
    printf("Breath First Search\n");
    bfs_mat(g, 0);
    printf("\n");
    free(g);
    return 0;
}
