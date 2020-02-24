#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct _DListNode{
    element data;
    struct _DListNode *llink;
    struct _DListNode *rlink;
}DListNode;

void init(DListNode *phead)
{
    phead->rlink = phead;
    phead->llink = phead;
}

void print_list(DListNode *phead)
{
    DListNode *p;
    for(p = phead->rlink; p != phead; p = p->rlink){
        printf("<-|%d|->", p->data);
    }
    printf("\n");
}

void dinsert(DListNode *before, element data)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode *phead, DListNode *removed)
{
    if(removed == phead)
        return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main(){
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    printf("추가 단계\n");
    for(int i = 0; i < 5; i++){
        dinsert(head, i);
        print_list(head);
    }
    printf("\n삭제 단계\n");
    for(int i = 0; i < 5; i++){
        print_list(head);
        ddelete(head, head->llink);
    }
    free(head);
}