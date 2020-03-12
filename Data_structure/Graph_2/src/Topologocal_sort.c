#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_STACK_SIZE 100

typedef struct _GraphNode{
    int vertex;
    struct _GraphNode *link;
} GraphNode;

typedef struct _GraphType{
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

typedef struct{
    int stack[MAX_STACK_SIZE];
    int top;
} StackType;

void graph_init(GraphType *g)
{
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++)
        g->adj_list[i] = NULL;
}

void stack_init(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    return s->top == -1;
}

int is_full(StackType *s)
{
    return s->top == MAX_STACK_SIZE-1;
}

void push(StackType *s, int item)
{
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->stack[++s->top] = item;
}

int pop(StackType *s)
{
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } else
        return s->stack[s->top--];
}

void insert_vertex(GraphType *g, int v)
{
    if(g->n + 1 > MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v)
{
    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

int topo_sort(GraphType *g)
{
    int i;
    StackType s;
    GraphNode *node;

    int *in_degree = (int *)malloc(g->n * sizeof(int));
    for(i = 0; i < g->n; i++){      // 초기화
        in_degree[i] = 0;
    }
    for(i = 0; i < g->n; i++){
        GraphNode *node = g->adj_list[i];
        while(node != NULL){
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    stack_init(&s);
    for(i = 0; i < g->n; i++){
        if(in_degree[i] == 0)
            push(&s, i);
    }

    while(!is_empty(&s)){
        int w;
        w = pop(&s);
        printf("정점 %d ->", w);
        node = g->adj_list[w];
        while(node != NULL){
            int u = node->vertex;
            in_degree[u]--;
            if(in_degree[u] == 0)
                push(&s, u);
            node = node->link;
        }
    }

    free(in_degree);
    printf("\n");
    return (i == g->n);
}

int main()
{
    GraphType g;

    graph_init(&g);
    for(int i = 0; i < 6; i++)
        insert_vertex(&g, i);

    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);

    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);

    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 5);

    insert_edge(&g, 3, 5);

    insert_edge(&g, 4, 5);

    topo_sort(&g);
}