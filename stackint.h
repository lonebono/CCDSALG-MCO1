#define MAX_INT 255

typedef struct {
    int stackint[MAX_INT];
    int top;
} Stack;

void createStack(Stack *s);
int isStackFull(Stack *s);
int isStackEmpty(Stack *s);
void push(Stack *s, int newNum);
int pop(Stack *s);