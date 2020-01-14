#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int top;
}StackType;

void init_stack(StackType *s){
    s->top = -1;
    s->capacity = 1;
    s->data = (int *)malloc(sizeof(int));
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == s->capacity-1);
}

void push(StackType *s, int data){
    if(is_full(s)){
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, s->capacity* sizeof(int));
    }
    s->data[++(s->top)] = data;
}

int pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
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
    free(s.data);
}