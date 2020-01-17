#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct{
    element queue[MAX_QUEUE_SIZE];
    int rear, front;
}QueueType;

void init_queue(QueueType *q){
    q->front = -1;
    q->rear = -1;
}

int is_empty(QueueType *q){
    return (q->rear == q->front );
}

int is_full(QueueType *q){
    return (q->rear == MAX_QUEUE_SIZE-1 );
}

void enqueue(QueueType *q, element e){
    if(is_full(q)){
        fprintf(stderr, "큐 포화 에러\n");
        exit(1);
    }
    q->queue[++(q->rear)] = e;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "큐 공백 에러\n");
        exit(1);
    }
    return q->queue[++(q->front)];
}

element peek(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "큐 공백 에러\n");
        exit(1);
    }
    return q->queue[(q->front)+1];
}

int main(){
    QueueType q;

    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", is_empty(&q));
}
