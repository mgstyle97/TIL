#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef struct{
    int stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == MAX_STACK_SIZE-1);
}

void push(StackType *s, int element){
    if(is_full(s)){
        fprintf(stderr, "���� ��ȭ ����\n");
        exit(1);
    } else
        s->stack[++(s->top)] = element;
}

int pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    } else
        return s->stack[(s->top)--];
}

int peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->stack[s->top];
}

int main(){
    StackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));
}