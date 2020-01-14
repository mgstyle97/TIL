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
        fprintf(stderr, "메모리 할당 에러\n");
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
        fprintf(stderr, "스택 공백 에러\n");
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
        fprintf(stderr, "스택 공백 에러\n");
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
