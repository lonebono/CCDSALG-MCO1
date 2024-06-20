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
