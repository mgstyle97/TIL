#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct _DListNode{
    element data;
    struct _DListNode *llink;
    struct _DListNode *rlink;
}DListNode;

DListNode *current;

void init(DListNode *phead)
{
    phead->rlink = phead;
    phead->llink = phead;
}

void print_list(DListNode *phead)
{
    DListNode *p;
    for(p = phead->rlink; p != phead; p = p->rlink){
        if(p == current)
            printf(" <-|#%s#|-> ", p->data);
        else
            printf(" <-|%s|-> ", p->data);
    }
    printf("\n");
}

void dinsert(DListNode *before, element data)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    strcpy(newnode->data, data);
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode *head, DListNode *removed)
{
    if(removed == head)
        return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main()
{
    char ch;
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);

    dinsert(head, "Mamamia");
    dinsert(head, "Dancong Queen");
    dinsert(head, "Fernando");

    current = head->rlink;
    print_list(head);

    do{
        printf("\n 명령어를 입력하시오( <, >,q): ");
        ch = getchar();
        if(ch == '<'){
            current = current->llink;
            if(current == head)
                current = current->llink;
        }
        else if(ch == '>'){
            current = current->rlink;
            if(current == head)
                current = current->rlink;
        }
        print_list(head);
        getchar();
    }while(ch != 'q');

    free(head);
}