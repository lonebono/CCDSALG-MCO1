#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 256
typedef char string[SIZE]; //just for strings in general

int main(void) 
{
    string infix;
    string postfix;
    queueArray array;
    int numElem = 0;
    
    while (strcmp(infix, "QUIT") != 0) {
        
        scanf("%s", infix);
        
        infix_to_postfix(infix, &postfix);
        
        printf("%s\n", postfix); //infix converted to postfix expression
        
        queuedPostfix(&array, postfix, &numElem);
        
        printf("Evaluated Value: \n"); //evaluated value
        printf("\n");
        
        strcpy(postfix, "");
    }
    
    return 0;
}
