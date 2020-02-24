#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *rlink;
    struct DlistNode *llink;
}DlistNode;

typedef struct DequeType{
    DlistNode *head, *tail;
}DequeType;

void init(DequeType *dq){
    dq->head = dq->tail = NULL;
}

DlistNode *create_node(DlistNode *llink, element item, DlistNode *rlink){
    DlistNode *temp = (DlistNode *)malloc(sizeof(DlistNode));
    if(temp == NULL){
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }
    temp->llink = llink;
    temp->data = item;
    temp->rlink = rlink;
    return temp;
}

int is_empty(DequeType *dq){
    return dq->head == NULL;
}

void add_rear(DequeType *dq, element e){
    DlistNode *new_node = create_node(dq->tail, e, NULL);
    if(is_empty(dq))
        dq->head = new_node;
    else
        dq->tail->rlink = new_node;
    dq->tail = new_node;
}

void add_front(DequeType *dq, element e){
    DlistNode *new_node = create_node(NULL, e, dq->head);
    if(is_empty(dq))
        dq->tail = new_node;
    else
        dq->head->llink = new_node;
    dq->head = new_node;
}

element delete_rear(DequeType *dq){
    element item;
    DlistNode *removed_node;
    if(is_empty(dq)){
        fprintf(stderr, "덱 공백 에러\n");
        exit(1);
    }
    else{
        removed_node = dq->tail;
        item = removed_node->data;
        dq->tail = removed_node->llink;
        if(dq->tail == NULL)
            dq->head = NULL;
        else
            dq->tail->rlink = NULL;
    }
    return item;
}

element delete_front(DequeType *dq){
    element item;
    DlistNode *removed_node;
    if(is_empty(dq)){
        fprintf(stderr, "덱 공백 에러\n");
        exit(1);
    }
    else{
        removed_node = dq->head;
        item = removed_node->data;
        dq->head = removed_node->rlink;
        if(dq->head == NULL)
            dq->tail = NULL;
        else
            dq->head->llink = NULL;
    }
    return item;
}

void display(DequeType *dq){
    DlistNode *p;
    printf("(");
    for(p=dq->head;p!=NULL;p=p->rlink){
        printf("%d", p->data);
    }
    printf(")\n");
}

int main(){
    DequeType dq;

    init(&dq);
    add_front(&dq, 10);
    add_front(&dq, 20);
    add_rear(&dq, 30);
    display(&dq);

    delete_front(&dq);
    delete_rear(&dq);
    display(&dq);
}