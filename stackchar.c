#include <stdio.h>
#include <stdlib.h>
#include "stackchar.h"

void createStack(Stack *s){
    s->top = -1;
}

int isStackFull(Stack *s){
    if (s->top == MAX_CHAR - 1)
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

int top(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stackchar[s->top];
}

void push(Stack *s, char newChar){
    if(isStackFull == 1){
        printf("Stack Overflow!\n");
    }
    else{
        s->stackchar[++(s->top)] = newChar;
    }
}

char pop(Stack *s){
    if(isStackEmpty == 1){
        printf("Stack Underflow!\n");
    }
    else{
        return s->stackchar[(s->top)--];
    }
}
