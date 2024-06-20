#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 256
typedef char string[SIZE]; //just for strings in general

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
    strcpy(*result, "");
    strncat(*result, &c, 1);
}

int icp(string op) {
    if (strcmp(op, "^") == 0)
        return 9;
    else if (strcmp(op, "/") == 0 || strcmp(op, "*") == 0)
        return 8;
    else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 7;
    else if (strcmp(op, ">") == 0 || strcmp(op, "<") == 0)
        return 6;
    else if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0)
        return 5;
    else if (strcmp(op, "!") == 0)
        return 4;
    else if (strcmp(op, "&&") == 0)
        return 3;
    else if (strcmp(op, "||") == 0)
        return 2;
    else
        return 0;
}

int isp(string op) {
    if (strcmp(op, "^") == 0)
        return 9;
    else if (strcmp(op, "/") == 0 || strcmp(op, "*") == 0)
        return 8;
    else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 7;
    else if (strcmp(op, ">") == 0 || strcmp(op, "<") == 0 || strcmp(op, ">=") == 0 || strcmp(op, "<=") == 0)
        return 6;
    else if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0)
        return 5;
    else if (strcmp(op, "!") == 0)
        return 4;
    else if (strcmp(op, "&&") == 0)
        return 3;
    else if (strcmp(op, "||") == 0)
        return 2;
    else if (strcmp(op, "(") == 0)
        return 1;
    else
        return 0;
}

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
 


void infix_to_postfix(string infix, string *postfix){
    int i;
    string x, temp, topOperator;
    string stackOperators = "\0";
    string stackOperands = "\0";
    string operand = "\0";
    int len = strlen(infix);

    for (i = 0; i < len; i++){
        char c = infix[i];
        charToStr(c, &temp);

        if (isdigit(c)){
            strcat(stackOperands, temp);
            
            if (!isdigit(infix[i+1])) {
                enqueue(postfix, stackOperands);
                strcpy(stackOperands, "");
            }
        }
        else {
            if (c == '(') {
                push(stackOperators, temp);
            }
            else if (c == ')') {
                top(stackOperators, topOperator);
                
                while (icp(topOperator) != 0 && strlen(stackOperators) != 0) {
                    enqueue(postfix, topOperator);
                    pop(stackOperators, x);
                    top(stackOperators, topOperator);
                }
                pop(stackOperators, x);
            }
            else {
                strcat(operand, temp);
                //printf(">%s\n", operand);

                if (isdigit(infix[i+1]) || infix[i+1] == '(' || infix[i+1] == ')') {
                    top(stackOperators, topOperator);
                    if (icp(operand) > isp(topOperator)) {
                        push(stackOperators, operand);
                    }
                    else {
                        top(stackOperators, topOperator);
                        while ((icp(operand) <= isp(topOperator)) && (strlen(stackOperators) != 0)) {
                            enqueue(postfix, topOperator);
                            pop(stackOperators, x);
                            top(stackOperators, topOperator);
                        }
                        push(stackOperators, operand);
                    }
                    strcpy(operand, "");
                }
            }
        }
    }
    while (strlen(stackOperators) != 0) {
        pop(stackOperators, x);
        enqueue(postfix, x);
    }
}


int main() {
     
    string infix;
    string postfix;

    while (strcmp(infix, "QUIT") != 0) {
        printf("Enter an infix expression: ");

        scanf("%s", infix);
        
        infix_to_postfix(infix, &postfix);
        
        printf("Postfix expression: %s\n", postfix);
        printf("Evaluated Value: \n");
        printf("\n");
        
        strcpy(postfix, "");
    }
    
    return 0;
}
