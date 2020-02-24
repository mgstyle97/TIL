#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct{
    element stack[MAX_STACK_SIZE];
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

void push(StackType *s, element data){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    } else
        s->stack[++(s->top)] = data;
}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } else
        return s->stack[(s->top)--];
}

element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[s->top];
}

int check_matching(char *in){
    StackType s;
    char ch, open_ch;
    int n = strlen(in);
    init_stack(&s);

    for(int i = 0; i < n; i++){
        ch = in[i];
        switch(ch){
            case '(': case '{': case '[':
                push(&s, ch);
                break ;
            case ')': case '}': case ']':
                if(is_empty(&s))
                    return false;
                else{
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')')||
                       (open_ch == '{' && ch != '}')||
                       (open_ch == '[' && ch != ']')){
                        return false;
                    }
                    break ;
                }
        }
    }
    if(!is_empty(&s))
        return false;
    return true;
}

int main(){
    if(check_matching("{ A[(i+1)]=0; }"))
        printf("괄호검사성공\n");
    else
        printf("괄호검사실패\n");
}
