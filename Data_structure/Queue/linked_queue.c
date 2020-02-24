#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode{
    element data;
    struct QueueNode *link;
}QueueNode;

typedef struct{
    QueueNode *front;
    QueueNode *rear;
}LinkedQueueType;

void init_queue(LinkedQueueType *q){
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(LinkedQueueType *q){
    return q->rear == NULL;
}

void enqueue(LinkedQueueType *q, element e){
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    if(temp == NULL){
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    else{
        temp->data = e;
        temp->link = NULL;
        if(is_empty(q)){
            q->rear = temp;
            q->front = temp;
        }
        else{
            q->rear->link = temp;
            q->rear = temp;
        }
    }
}

element dequeue(LinkedQueueType *q){
    QueueNode *temp = q->front;
    element item;
    if(is_empty(q)){
        fprintf(stderr, "큐 공백 에러\n");
        exit(1);
    }
    else{
        item = temp->data;
        q->front = temp->link;
        if(q->front == NULL)
            q->rear = NULL;
        free(temp);
        return item;
    }
}

element peek(LinkedQueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "큐 공백 에러\n");
        exit(1);
    }
    return q->front->data;
}

int main(){
    LinkedQueueType q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("%d\n", is_empty(&q));
}