#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 256
typedef char string[SIZE]; // Defines string type for convenience

// Struct definitions for Stack and Queue

typedef struct {
    char stackint[SIZE]; // Stack array for operators
    char top; // Top index of the stack
} Stack;

typedef struct {
    string queue; // Array to hold postfix expression tokens
    char front, rear; // Front and rear indices for the queue
} Queue;

typedef Queue queueArray[SIZE]; // Array of queues to hold tokens of postfix expression

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

char queueHead(string s)
{
    // Function to get the first character of a string (used as a queue)
    if (strlen(s) == 0)
    {
        return '\0'; // Returns null character if string is empty
    }
    else
    {
        return s[0]; // Otherwise, returns the first character of the string
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
    // Function to convert infix expression to postfix expression
    int i;
    string x, temp, topOperator;
    string stackOperators = "\0"; // Stack to hold operators
    string stackOperands = "\0"; // Stack to temporarily hold operands
    string operand = "\0"; // Current operand being formed
    int len = strlen(infix);

    for (i = 0; i < len; i++)
    {
        char c = infix[i];
        charToStr(c, &temp); // Converts character to string

        if (isdigit(c))
        {
            strcat(stackOperands, temp); // Appends digit to operand stack (for numbers with more than 1 digits e.x 123, 56)

            if (!isdigit(infix[i + 1]))
            {
                enqueue(postfix, stackOperands); // Enqueues operand as part of postfix expression
                strcpy(stackOperands, ""); // Clears operand stack
            }
        }
        else
        {
            if (c == '(')
            {
                push(stackOperators, temp); // Pushes '(' onto operator stack
            }
            else if (c == ')')
            {
                top(stackOperators, topOperator); // Gets top operator from stack

                // Pops operators from stack to postfix until '(' encountered
                while (icp(topOperator) != 0 && strlen(stackOperators) != 0)
                {
                    enqueue(postfix, topOperator); // Enqueues operator to postfix expression
                    pop(stackOperators, x); // Pops operator from stack
                    top(stackOperators, topOperator); // Gets new top operator
                }
                pop(stackOperators, x); // Pops '(' from stack
            }
            else
            {
                strcat(operand, temp); // Concatenates characters to form operator (for operators with more than 1 character e.x. !=, &&)

                if (isdigit(infix[i + 1]) || infix[i + 1] == '(' || infix[i + 1] == ')')
                {
                    top(stackOperators, topOperator); // Gets top operator from stack

                    // Compares precedence of current operand with top operator in stack
                    if (icp(operand) > isp(topOperator))
                    {
                        push(stackOperators, operand); // Pushes operand onto stack
                    }
                    else
                    {
                        top(stackOperators, topOperator);

                        // Pops operators to postfix until precedence condition met
                        while ((icp(operand) <= isp(topOperator)) && (strlen(stackOperators) != 0))
                        {
                            enqueue(postfix, topOperator); // Enqueues operator to postfix expression
                            pop(stackOperators, x); // Pops operator from stack
                            top(stackOperators, topOperator); // Gets new top operator
                        }
                        push(stackOperators, operand); // Pushes operand onto stack
                    }
                    strcpy(operand, ""); // Clears operand string for next use
                }
            }
        }
    }

    // Pops remaining operators in stack to postfix expression
    while (strlen(stackOperators) != 0)
    {
        pop(stackOperators, x); // Pops operator from stack
        enqueue(postfix, x); // Enqueues operator to postfix expression
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

void printQueued(queueArray *array, int numElem)
{
    // Function to print each queue element in the array
    int i;
    for (i = 0; i < numElem; i++)
    {
        printf("Token in index %d: %s \n", i, (*array)[i].queue); // Prints each token queue
    }
}

int main(void)
{
    string infix;
    string postfix;
    queueArray array;
    int numElem = 0;

    while (1)
    {
        printf("Enter an infix expression (or QUIT to exit): ");
        scanf("%s", infix);

        if (strcmp(infix, "QUIT") == 0)
            break;

        infix_to_postfix(infix, &postfix); // Converts infix to postfix
        printf("Postfix expression: %s\n", postfix); // Prints postfix expression

        queuedPostfix(&array, postfix, &numElem); // Parses postfix into array of queues
        printQueued(&array, numElem); // Prints each token queue
    }

    return 0;
}

