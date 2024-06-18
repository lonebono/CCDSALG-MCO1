#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256 //255 characters

// implement the queue code algorithm 

typedef struct Queue {
    char *eval[MAX_CHAR];
    int front, rear;
} Queue;

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

void dequeue(Queue *q) {
    int value;
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
