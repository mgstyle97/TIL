#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    int item;
    struct StackNode *link;
}StackNode;

typedef struct{
    StackNode *top;
}LinkedStackType;

void init_stack(LinkedStackType *s){
    s->top = NULL;
}

int is_empty(LinkedStackType *s){
    return (s->top == NULL);
}

void push(LinkedStackType *s, int item){
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    if(temp == NULL){
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        return;
    }
    else{
        temp->item = item;
        temp->link = s->top;
        s->top = temp;
    }
}

int pop(LinkedStackType *s){
    if(is_empty(s)){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    } else{
        StackNode *temp = s->top;
        int item = temp->item;
        s->top = temp->link;
        free(temp);
        return item;
    }
}

int peek(LinkedStackType *s){
    if(is_empty(s)){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    } else
        return s->top->item;
}

int main(){
    LinkedStackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));
}
