#include <stdio.h>
#include <stdlib.h>
#include "stackint.h"

void createStack(Stack *s){
    s->top = -1;
}

int isStackFull(Stack *s){
    if (s->top == MAX_INT - 1)
        return 1;
    else 
        return 0;
}

int isStackEmpty(Stack *s){
    if (s->top == -1)
        return 1;
    else 
        return 0;
}

void push(Stack *s, int newNum){
    if(isStackFull == 1){
        printf("Stack Overflow!\n");
    }
    else{
        s->stackint[++(s->top)] = newNum;
    }
}

int pop(Stack *s){
    if(isStackEmpty == 1){
        printf("Stack Underflow!\n");
    }
    else{
        return s->stackint[(s->top)--];
    }
}
