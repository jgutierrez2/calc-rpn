#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "InputTypes.h"

typedef struct String { char str[150]; } String;

Stack *stack;

int strLen(char *str){
    int i = 0;
    while ( str[i] != '\0') {
        i++;
    }
    i++;
    
    return i;
}

void show() {
    system("cls");
    
    String strs[10];
    
    printf("----------------------\n");
    
    int k;
    for (k=0; k < 10; k++) sprintf(strs[k].str, "| %i.", 9 - k);
    
    for (k=9; k > 9 - size(stack); k--) {
        char str[20];
        sprintf(str, "%i", at(stack, size(stack)-(9-k)));
        
        int length = 20 - strLen(str) - strLen(strs[k].str);
        
        int i;
        for (i = 0; i < length; i++) {
            sprintf(strs[k].str, "%s%s", strs[k].str, " ");
        }
        
        sprintf(strs[k].str, "%s %s", strs[k].str, str);
    }
    
    for (k=0; k < 10; k++) {
        int length = 22 - strLen(strs[k].str);
        
        int i;
        for ( i = 0; i < length; i++) {
            sprintf(strs[k].str, "%s%s", strs[k].str, " ");
        }
        
        printf("%s|\n",strs[k].str);
    }
    
    printf("----------------------\n");
    
    printf("-Input: ");
}

void next(){
    char input[50];
    Type t = getInput(input,50);
    
    switch (t) {
        case Num: {
            push(stack, atoi(input));
            break;
        }
        case Sym: {
            int r = pop(stack);
            int l = pop(stack);
            if (*input == '+') { push(stack, l+r); }
            else if (*input == '-') { push( stack, l-r); }
            else if (*input == '*') { push( stack, l*r); }
            else if (*input == '/') { push( stack, l/r); }
            break;
        }
        default : {
            break;
        }
    }
    
    show();
}

int main(){
    stack = newstack();
    
    
    show();
    while(1){
        next();
    }
}