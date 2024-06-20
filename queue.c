#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

//For infix-postfix conversion
void enqueue(string *s, string element)
{
    if (strlen(*s) == 0) //if queue is empty, simply copy the element
    {
        strcpy(*s, element);
    }
    else //if queue is not empty, put ' '/space first then copy the element
    {
        strcat(*s, " ");
        strcat(*s, element);
    }
}

char queueHead(string s)
{
    if (strlen(s) == 0) //return null byte if queue is empty
    {
        return '\0';
    }
    else  //return element in first index 
    {
        return s[0];
    }
}

// implement the queue code algorithm 

void endsOfQueue(Queue *q) {
    q->front = -1;
    q->rear = 0;
}

void isQueueEmpty(Queue *q) {
    if (q->front == -1){
        return 1;
    }
    else
        return 0;
}

void isQueueFull(Queue *q) {
   if (((q->front == 0 && q->rear == MAX_CHAR - 1) || (q->front == q->rear + 1)))
   {
        return 1;
   }
   else
        return 0;
}

void enqueue(Queue *q, int value) {
    if (isQueueFull == 0) {
        printf("Queue is Full!\n");
    } else {
        if (q->front == -1) 
            q->front = 0;
        q->eval[q->rear] = value;
        q->rear = q->rear + 1; // q->rear = (q->rear + 1) % MAX_CHAR;
    }
}

char dequeue(Queue *q) {
    char value; //returns a char
    if (isQueueEmpty == 0){
        printf("Queue is Empty!\n");
        return -1;
    }
    else {
        value = q->eval[q->front];
        if(q->front == q->rear - 1) { // reset
            q->front = -1;
            q->rear = 0;
        }
        else {
            q->front = q->front + 1; // q->front = (q->front + 1) % MAX_CHAR
        }
        return value;
    }
}
