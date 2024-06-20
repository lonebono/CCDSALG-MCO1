#define MAX_CHAR 256 //255 characters

typedef struct Queue {
    char *eval[MAX_CHAR];
    int front, rear;
} Queue;

void endsOfQueue(Queue *q);
void isQueueEmpty(Queue *q);
void isQueueFull(Queue *q);
void enqueue(Queue *q, int value);
char dequeue(Queue *q);