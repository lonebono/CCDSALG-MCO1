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
            strcat(element, s);
            strcpy(s, element);
        }
    }
}

char pop(string *s)
{
    string popped;
    int i, j, lastSpaceIndex = -1;

    // Check if the string is empty
    if (strlen(*s) == 0)
    {
        printf("\nUnderflow Error!");
        return top(*s);
    }
    else
    {
        for (i = 0; i < strlen(*s); i++)
        {
            if ((*s)[i] == ' ')
            {
                lastSpaceIndex = i;
            }
        }

        // Handle the case where the string has only one element
        if (lastSpaceIndex != -1)
        {
            strcpy(popped, &(*s)[lastSpaceIndex + 1]);
            (*s)[lastSpaceIndex] = '\0';
        }
        else
        {
            strcpy(popped, *s);
            for (j = 0; j < strlen(*s); j++){
                (*s)[j] = (*s)[j+1];
            }
            *s[strlen(*s)] = '\0';
        }

        return *popped;
    }
}

void enqueue(string *s, string element)
{

    if (strlen(*s) == 0)
    {
        strcpy(*s, element);
    }
    else
    {
        strcat(*s, " ");
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

int precedence(string op) {
    if (strcmp(op, "^") == 0)
        return 3;
    else if (strcmp(op, "/") == 0 || strcmp(op, "*") == 0)
        return 2;
    else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 1;
    else
        return 0;
}

void infix_to_postfix(string infix, string *postfix){
    int i = 0;
    string temp, temp2, temp3, temp4;
    string stack = "\0";
    int len = strlen(infix);

    while (i <= len-1){
        strcpy(temp, "");
        strcpy(temp2, "");
        strcpy(temp3, "");
        strcpy(temp4, "");
        
        char c = infix[i];

        if (isdigit(c)){
            int token_index = 0;
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
            printf(">%c\n", top(stack));
            charToStr(top(stack), &temp2);
            printf(">%s\n", temp2);
            while ((precedence(temp2) != 0) && (strlen(stack) != 0)){
                charToStr(pop(&stack), &temp);
                enqueue(postfix, temp);
                charToStr(top(stack), &temp3);
            }
            pop(&stack);
            i++;
        }
        else{
            charToStr(c, &temp4);
            charToStr(top(stack), &temp2);
            charToStr(c, &temp3);
            if (precedence(temp4) > precedence(temp2)){
                push(stack, temp4);
            }
            else {
                while ((precedence(temp3) <= precedence(temp2)) && (strlen(stack) != 0)){
                    charToStr(pop(&stack), &temp);
                    enqueue(postfix, temp);
                    charToStr(top(stack), &temp2);
                }
                push(stack, temp3);
            }
            i++;
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
