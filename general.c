#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include general.h

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

void infix_to_postfix(string infix, string *postfix){
    int i;
    string x, temp, topOperator;
    string stackOperators = "\0";
    string stackOperands = "\0";
    string operand = "\0";
    int len = (int)strlen(infix);

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

void postfix_to_queue(queueArray *array, string postfix, int *numElem)
{
    int i = 0, j = 0, k = 0;
    while (k < strlen(postfix))
    {
        if (postfix[k] != ' ')
        {
            while (postfix[k] != ' ' && postfix[k] != '\0')
            {
                (*array)[i].queue[j] = postfix[k];
                j++;
                k++;
            }
            (*array)[i].queue[j] = '\0'; // Null-terminate the string
            i++;
            j = 0;
        }
        else
        {
            (*array)[i].queue[0] = ' ';
            (*array)[i].queue[1] = '\0'; // Null-terminate the string
            i++;
            k++;
        }
    }
    *numElem = i; // Update the number of elements
}
