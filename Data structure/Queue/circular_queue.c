#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void init_queue(QueueType *q){
    q->rear = q->front = 0;
}

int is_empty(QueueType *q){
    return (q->rear == q->front);
}

int is_full(QueueType *q){
    return (((q->rear)+1)%MAX_QUEUE_SIZE == (q->front)%MAX_QUEUE_SIZE);
}

void enqueue(QueueType *q, element e){
    if(is_full(q)){
        fprintf(stderr, "큐 포화 에러\n");
        exit(1);
    }
    q->queue[++(q->rear)%MAX_QUEUE_SIZE] = e;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "큐 공백 에러\n");
        exit(1);
    }
    return (q->queue[++(q->front)%MAX_QUEUE_SIZE]);
}

element peek(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "큐 콩백 에러\n");
        exit(1);
    }
    return (q->queue[(q->front+1)%MAX_QUEUE_SIZE]);
}

int main(){
    QueueType q;
    init_queue(&q);
    printf("front=%d rear=%d\n", q.front, q.rear);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("dequeue()=%d\n", dequeue(&q));
    printf("dequeue()=%d\n", dequeue(&q));
    printf("dequeue()=%d\n", dequeue(&q));
    printf("front=%d rear=%d\n", q.front, q.rear);

}