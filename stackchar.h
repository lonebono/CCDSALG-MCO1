#define MAX_CHAR 256

typedef struct {
    int stackchar[MAX_CHAR];
    int top;
} Stack;

void createStack(Stack *s);
int isStackFull(Stack *s);
int isStackEmpty(Stack *s);
int top(Stack *s);
void push(Stack *s, int newNum);
char pop(Stack *s);