#include <stdio.h>
#include <stdlib.h>
#include "stackchar.h"

//for infix to postfix conversion
void top(string s, string result)
{
    int lastSpaceIndex = -1;
    int i;

    if (strlen(s) == 0)
    {
        result[0] = '\0';
    }
    else
    {
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] == ' ')
            {
                lastSpaceIndex = i;
            }
        }
        if (lastSpaceIndex == -1)
        {
            strcpy(result, s);
        }
        else
        {
            strcpy(result, &s[lastSpaceIndex + 1]);
        }
    }
}

void push(string s, string element)
{
    if (strlen(s) == SIZE -1)
    {
        printf("\nOverflow Error!");
    }
    else
    {
        if (strlen(s) == 0)
        {
            strcpy(s, element);
        }
        else
        {
            strcat(s, " ");
            strcat(s, element);
        }
    }
}

void pop(string s, string result)
{
    int i;
    int lastSpaceIndex = -1;
    string temp;

    if (strlen(s) == 0)
    {
        printf("\nUnderflow Error!");
    }
    else
    {
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] == ' ')
            {
                lastSpaceIndex = i;
            }
        }
        if (lastSpaceIndex != -1)
        {
            top(s, temp);
            strcpy(result, temp);
            s[lastSpaceIndex] = '\0';
        }
        else
        {
            top(s, temp);
            strcpy(result, temp);
            s[0] = '\0';
        }
    }
}

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
