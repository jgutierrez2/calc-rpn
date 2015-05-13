#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Calculator.h"
#include "Stack.h"
#include "Storage.h"

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

void clearStack(Calculator *c) {
  clearStorage(c->mem);
}

void storeValue(Calculator *c, int i){
    int j = pop(c->stack);
    store(c->mem, i, j);
    push(c->stack, j);
    
}

int recallValue(Calculator *c, int i){
    return recall(c->mem, i);
}

void display(Calculator *c) {
    
    int colWidth[5] = {4, 15, 12, 20 ,20};
    int rowCount = 15;
    char strs[5][50][20]; // 5 columns, 50 rows each, of length 20 strings
    char temp[20];          //placeholder string
    
    int i;
    
//1st column contains stack indices
    for (i = 0; i < rowCount; i++) {
        sprintf(temp,"%i",rowCount - 1 - i);
        sprintf(strs[0][i],"%.*s%s", (int)(colWidth[0]-strlen(temp)),"    ",temp);
    }
    
//2nd column contains stack values
    for (i = 0; i < size(c->stack); i++) {
        sprintf(temp,"%i",at(c->stack, size(c->stack) - i - 1));
        sprintf(strs[1][rowCount-1-i],"%.*s%s",(int)(colWidth[1]-strlen(temp)), "                    ",temp);
    }
    
    for (i = 0; i < rowCount - size(c->stack); i++) {
        sprintf(strs[1][i],"%.*s",colWidth[1],"               ");
    }
    
//3rd column contains values in memory
    for (i = 0; i < 10; i++) {
        sprintf(temp,"%i",recall(c->mem,i));
        sprintf(strs[2][i],"r %i. %.*s%s",i,(int)(colWidth[2]-strlen(temp)), "                    ",temp);
    }
    
    for (i = 10; i < 50; i++) {
        sprintf(strs[2][i],"%.*s",colWidth[2]+5,"                  ");
    }

//print to screen
    
    system("clear");
    
    printf("   i       Stack              Mem       \n");
    printf("----------------------------------------\n");
    
    for (i = 0; i < rowCount; i++) {
        printf("|%s|%s|%s|\n", strs[0][i], strs[1][i], strs[2][i]);
    }
    
    printf("----------------------------------------\n");

    printf("\nInput:");

}
