#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(){
    return (top == -1);
}
int is_full(){
    return (top == MAX_STACK_SIZE-1);
}

void push(int element){
    if(is_full()){
        fprintf(stderr, "���� ��ȭ ����\n");
        exit(1);
    } else
        stack[++top] = element;
}
int pop(){
    if(is_empty()){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    } else
        return stack[top--];
}

int peek(){
    if(is_empty()){
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else
        return stack[top];
}

int main(){
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", is_empty());
}