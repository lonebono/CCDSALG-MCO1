typedef struct {
    char stackint[SIZE];
    char top;
} Stack;

//for infix to postfix for conversion
void top(string s, string result)
void push(string s, string element)
void pop(string s, string result)


void createStack(Stack *s);
int isStackFull(Stack *s);
int isStackEmpty(Stack *s);
int top(Stack *s);
void push(Stack *s, int newNum);
char pop(Stack *s);
