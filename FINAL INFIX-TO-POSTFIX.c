#include "infix-to-postfix.h"

void enqueue(string *s, string element)
{
    // Function to enqueue (add) an element to the end of a string (used as a queue)
    if (strlen(*s) == 0)
    {
        strcpy(*s, element); // If string is empty, copies element directly
    }
    else
    {
        strcat(*s, " "); // Otherwise, adds a space separator
        strcat(*s, element); // Then concatenates the element
    }
}

void charToStr(char c, string *result)
{
    // Function to convert a character to a string
    strcpy(*result, ""); // Clears the result string
    strncat(*result, &c, 1); // Concatenates the character to the result string
}

int icp(string op)
{
    // Function to return the 'in-coming precedence' of an operator
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
    else
        return 0; // Default precedence for unknown operators
}

int isp(string op)
{
    // Function to return the 'in-stack precedence' of an operator
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
        return 0; // Default precedence for unknown operators
}

void top(string s, string result)
{
    // Function to get the top element (last added) from a stack (string representation)
    int lastSpaceIndex = -1;
    int i;

    if (strlen(s) == 0)
    {
        result[0] = '\0'; // Returns empty string if stack is empty
    }
    else
    {
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] == ' ')
            {
                lastSpaceIndex = i; // Finds the last space in the stack string
            }
        }
        if (lastSpaceIndex == -1)
        {
            strcpy(result, s); // If no space found, copies entire stack string
        }
        else
        {
            strcpy(result, &s[lastSpaceIndex + 1]); // Otherwise, copies from after the last space
        }
    }
}

void push(string s, string element)
{
    // Function to push (add) an element onto a stack (string representation)
    if (strlen(s) == SIZE - 1)
    {
        printf("\nOverflow Error!"); // Checks if stack is full
    }
    else
    {
        if (strlen(s) == 0)
        {
            strcpy(s, element); // If stack is empty, copies element directly
        }
        else
        {
            strcat(s, " "); // Otherwise, adds a space separator
            strcat(s, element); // Then concatenates the element
        }
    }
}

void pop(string s, string result)
{
    // Function to pop (remove and return) an element from a stack (string representation)
    int i;
    int lastSpaceIndex = -1;
    string temp;

    if (strlen(s) == 0)
    {
        printf("\nUnderflow Error!"); // Checks if stack is empty
    }
    else
    {
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] == ' ')
            {
                lastSpaceIndex = i; // Finsd the last space in the stack string
            }
        }
        if (lastSpaceIndex != -1)
        {
            top(s, temp); // Gets the top element
            strcpy(result, temp); // Copies it to result
            s[lastSpaceIndex] = '\0'; // Removes the element by replacing space with null terminator
        }
        else
        {
            top(s, temp); // Gets the top element
            strcpy(result, temp); // Copies it to result
            s[0] = '\0'; // If no space found, clears the stack by setting first character to null terminator
        }
    }
}

void infix_to_postfix(string infix, string *postfix)
{
    int i;
    string x, temp, topOperator;
    string stackOperators = "\0";
    string stackOperands = "\0";
    string operand = "\0";
    int len = (int)strlen(infix);

    for (i = 0; i < len; i++)
    {
        char c = infix[i];
        charToStr(c, &temp);

        if (isdigit(c))
        {

            strcat(stackOperands, temp);

            if (!isdigit(infix[i+1])) 
            {
                enqueue(postfix, stackOperands);
                strcpy(stackOperands, "");
            }
        }
        else 
        {
            if (c == '(') 
            {
                push(stackOperators, temp);
            }
            else if (c == ')') 
            {
                top(stackOperators, topOperator);

                while (icp(topOperator) != 0 && strlen(stackOperators) != 0) 
                {
                    enqueue(postfix, topOperator);
                    pop(stackOperators, x);
                    top(stackOperators, topOperator);
                }
                pop(stackOperators, x);
            }
            else 
            {
                strcat(operand, temp);
                if (isdigit(infix[i+1]) || infix[i+1] == '(' || infix[i+1] == ')') {
                    top(stackOperators, topOperator);
                    if (icp(operand) > isp(topOperator)) 
                    {
                        push(stackOperators, operand);
                    }
                    else 
                    {
                        top(stackOperators, topOperator);
                        while ((icp(operand) <= isp(topOperator)) && (strlen(stackOperators) != 0)) 
                        {
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
    while (strlen(stackOperators) != 0) 
    {
        pop(stackOperators, x);
        enqueue(postfix, x);
    }
}

void queuedPostfix(queueArray *array, string postfix, int *numElem)
{
    // Function to parse postfix expression into an array of queues (for each token)
    int i = 0, j = 0, k = 0;
    while (k < strlen(postfix))
    {
        if (postfix[k] != ' ')
        {
            while (postfix[k] != ' ' && postfix[k] != '\0')
            {
                (*array)[i].queue[j] = postfix[k]; // Adds character to queue element
                j++;
                k++;
            }
            (*array)[i].queue[j] = '\0'; // Terminates string in queue element
            i++;
            j = 0;
        }
        else
        {
            (*array)[i].queue[0] = ' '; // Handles spaces between tokens
            (*array)[i].queue[1] = '\0'; // Terminates empty space
            i++;
            k++;
        }
    }
    *numElem = i; // Updates the number of elements in the array
}
