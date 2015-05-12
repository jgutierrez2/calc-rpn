#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Calculator.h"
#include "Stack.h"
#include "Storage.h"

char *keys[100];

struct Calculator {
  Stack *stack;
  Storage *mem;
};

Calculator *newCalculator(){
  Calculator *c = malloc(sizeof(Calculator));
  c->stack = newstack();
  c->mem = newStorage();
    
    return c;
}

void destroyCalculator(Calculator *c){
  destroystack(c->stack);
  destroyStorage(c->mem);
  free(c);
}

void input(Calculator *c, int i){
  push(c->stack,i);
}

void compute(Calculator *c, char *sym){
    sym[1] = '\0';
  if (strcmp(sym,"+") == 0 || strcmp(sym, "-") == 0 || strcmp(sym, "*") == 0 || strcmp(sym, "/") == 0 || strcmp(sym, "^") == 0) {
    int r = pop(c->stack);
    int l = pop(c->stack);
    
    switch (*sym) {
      case '+' : { push(c->stack, l+r); break; }
      case '-' : { push(c->stack, l-r); break; }
      case '*' : { push(c->stack, l*r); break; }
      case '/' : { push(c->stack, l/r); break; }
      case '^' : { push(c->stack, pow(l,r)); break; }
    }
  }
}

void display(Calculator *c) {
    system("clear");
    
    printf("   i       Stack\n");
    printf("----------------------\n");
    
    char *strs[5][50];
    char *temp = malloc(20*sizeof(char));

    int i;
    int j;
    
// 50 rows, 5 columns, size 20, prepare space for each
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 5; j++) {
            strs[j][i] = malloc(21*sizeof(char));
            sprintf(strs[j][i], "%s", "                   ");
        }
    }
    
//1st column contains stack indices
    for (i = 0; i < 50; i++) {
        sprintf(temp,"%i.",49 - i);
        sprintf(strs[0][i],"%.*s%s", (int)(4-strlen(temp)),"    ",temp);
    }
    
//2nd column contains stack values
    for (i = 0; i < size(c->stack); i++) {
        sprintf(temp,"%i",at(c->stack, i));
        sprintf(strs[1][49-i],"%.*s%s",(int)(15-strlen(temp)), "                    ",temp);
    }
    
    for (i = 0; i < 50 - size(c->stack); i++) {
        sprintf(strs[1][i],"%.*s",15,"               ");
    }
    
    for (i = 0; i < 50; i++) {
        printf("|%s|%s|\n", strs[0][i], strs[1][i]);
    }
    
    
    for (i = 0; i < 50; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            free(strs[j][i]);
        }
    }
    printf("----------------------\n");

    printf("\nInput:");

}
