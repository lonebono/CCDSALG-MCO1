#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 256
typedef char string[SIZE]; //just for strings in general

char top (string s)
{
    int lastSpaceIndex = -1;
    int i;

    if(strlen(s) == 0)
    {
        return '\0';
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

        return s[lastSpaceIndex + 1];
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
            s[strlen(s)] = *element;
        }
        else
        {
            strcat(s, element);
        }
    }
}

char pop(string *s)
{
    string popped;
    int i, lastSpaceIndex = -1;

    if (strlen(*s) == 0)
    {
        printf("\nUnderflow Error!");
        return top(*s);
    }
    else
    {
        for (i = 0; i < strlen(*s); i++)
        {
            if (*s[i] == ' ')
            {
                lastSpaceIndex = i;
            }
        }

        if (lastSpaceIndex != -1)
        {
            strcpy(popped, s[lastSpaceIndex + 1]);
            *s[lastSpaceIndex] = '\0';
        }
        else
        {
            strcpy(popped, *s);
            *s[0] = '\0';
        }

        return *popped;
    }
}

void enqueue(string *s, string element)
{

    if (strlen(*s) == 0)
    {
        *s[strlen(*s)] = *element;
    }
    else
    {
        *s[strlen(*s)] = ' ';
        strcat(*s, element);
    }
}

char queueHead (string s)
{
    
    if(strlen(s) == 0)
    {
        return '\0';
    }
    else
    {
        return s[0];
    }
}

void charToStr(char c, string *result){
    *result[0] = c;
    *result[1] = '\0';
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infix_to_postfix(string infix, string *postfix){
    int i = 0;
    string temp;
    string stack = "\0";
    int token_index;
    int len = strlen(infix);
    
    while (i < len){
        char c = infix[i];
        
        if (isdigit(c)){
            token_index = 0;
            while (isdigit(c)){
                temp[token_index++] = c;
                i++;
                c = infix[i];
            }
            temp[token_index] = '\0';
            enqueue(postfix, temp);
            strcpy(temp, "");
        }
        else if (c == '('){
            charToStr(c, &temp);
            push(stack, temp);
            strcpy(temp, "");
            i++;
        }
        else if (c == ')'){
            while (precedence(queueHead(stack)) > 0){
                charToStr(pop(&stack), &temp);
                enqueue(postfix, temp);
                strcpy(temp, "");
                i++;
            }
            
            pop(&stack);
        }
        else{
            if (precedence(c) > precedence(top(stack))){
                charToStr(c, &temp);
                push(stack, temp);
                strcpy(temp, "");
                i++;
            }
            else {
                while (precedence(c) <= precedence(top(stack))){
                    charToStr(c, &temp);
                    enqueue(postfix, temp);
                    strcpy(temp, "");
                    i++;
                }
            }
                
        }
    }
    while (strlen(stack) != 0) {
        charToStr(pop(&stack), &temp);
        enqueue(postfix, temp);
        strcpy(temp, "");
    }
}


int main() {
     string infix;
     string postfix;
     
     printf("Enter an infix expression: ");
     scanf("%s", infix);
     
     infix_to_postfix(infix, &postfix);
     printf("Postfix expression: %s\n", postfix);
     
     
    
    return 0;
}

