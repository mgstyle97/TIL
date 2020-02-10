#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct _TreeNode{
    int data;
    struct _TreeNode *left, *right;
}TreeNode;

#define MAX_QUEUE_SIZE 100
typedef TreeNode *element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return (q->rear+1 % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void level_order(TreeNode *root)
{
    QueueType q;

    init_queue(&q);

    if(root == NULL)
        return;
    enqueue(&q, root);
    while(!is_empty(&q)){
        root = dequeue(&q);
        printf("[%d] ", root->data);
        if(root->left)
            enqueue(&q, root->left);
        if(root->right)
            enqueue(&q, root->right);
    }
}

//      15
//  4       20
//1       16    25

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(){
    printf("레벨 순회=");
    level_order(root);
    printf("\n");
}
