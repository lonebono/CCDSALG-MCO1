#define SIZE 256
typedef char string[SIZE]; //just for strings in general

typedef struct {
    char stackint[SIZE];
    char top;
} Stack;

typedef struct {
    string queue;
    char front, rear;
} Queue;

typedef Queue queueArray[SIZE];

void charToStr(char c, string *result)
int icp(string op)
int isp(string op)
