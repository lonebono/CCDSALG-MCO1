#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.c"
#include "stackint.c"

#define MAX_CHAR 257

// code to evaluate the postfix is here
char tempConvert[MAX_CHAR];
int tempConverted;
char nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// char operators[][2] = {};

int convertCtoI(char tempConvert, int *tempConverted){
    return tempConverted = atoi(tempConvert);
}

int evalPostFix(Queue *q, char *tempConvert, int *tempConverted, Stack *s){
    int i = 0;
    int j;
    int result;
    createStack(&s);

    while(q->front != q->rear){
        if(q->eval[i] != ' '){
            strcmp(tempConvert[i], q->eval[i]);
            i++;
        }
        for(j = 0; j < 9; j++){
            if (strcmp(tempConvert[i], nums[i])) // if its a number push into stack else eval
                push(&s , convertCtoI(tempConvert, tempConverted));  
        }
        
        q->front = i; // sets the space where you are as the new front of the queue
    }

    return result; // done evaluating
}

int main(){

}