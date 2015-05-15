#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Calculator.h"
#include "Stack.h"
#include "Storage.h"
#include "InputInterface.h"

struct Calculator {
  Stack *stack;
  Storage *mem;
	
  char histComp[100][20];
  char histSol[100][20];
  int h;
    
  char rec[100];
  int r;
    
  void (*interface)(Calculator*, char*);
};

Calculator *newCalculator(void (*interface)(Calculator*,char*)){
  Calculator *c = malloc(sizeof(Calculator));
  c->stack = newstack();
  c->mem = newStorage();
  c->h = 0;
  c->r = 0;
    c->interface = interface;
  return c;
}

void record(Calculator *c){
    c->r = 1;
}

void endRec(Calculator *c){
    c->r = 0;
}

void destroyCalculator(Calculator *c){
  destroystack(c->stack);
  destroyStorage(c->mem);
  free(c);
}

void input(Calculator *c, int i){
  push(c->stack,i);
    
    char temp[20];
    sprintf(temp, " %i ", i);
    
    if (c->r) sprintf(c->rec, "%s %s", c->rec, temp);
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
 //     case '^' : { push(c->stack, pow(l,r)); break; }
    }
	  
	sprintf(c->histComp[c->h],"%i %s %i", l,sym,r);
	sprintf(c->histSol[c->h],"%i", at(c->stack,size(c->stack)-1));
	(c->h)++;
      
      char temp[20];
      sprintf(temp, "%s ", sym);
     if (c->r) sprintf(c->rec, "%s %s", c->rec, temp);
  }
}

void clearStack(Calculator *c) {
  while (size(c->stack) > 0) {
    pop(c->stack);
  }
  c->h = 0;
}

void deleteLast(Calculator *c) {
  pop(c->stack);
}

void storeValue(Calculator *c, int i){
    int j = pop(c->stack);
    store(c->mem, i, j);
    push(c->stack, j);
}

int recallValue(Calculator *c, int i){
    return recall(c->mem, i);
}

void run(Calculator* calc){
    char prog[100];
    sprintf(prog, "%s", calc->rec);
    
    char *in;
    in = strtok (prog," ");
    while (in != NULL) {
        calc->interface(calc,in);
        
        in = strtok (NULL, " \n");
    }
}

void display(Calculator *c) {
    
    int colWidth[5] = {4, 15, 12, 18 ,10};
    int rowCount = 10;
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
        sprintf(strs[2][i],"%.*s%s",(int)(colWidth[2]-strlen(temp)), "                    ",temp);
    }
    
    for (i = 10; i < rowCount; i++) {
        sprintf(strs[2][i],"%.*s",colWidth[2],"                  ");
    }
	
//4th column contains hist calcs
	for (i = 0; i < c->h; i++) {
		sprintf(temp,"%s",c->histComp[i]);
        sprintf(strs[3][i],"%.*s%s",(int)(colWidth[3]-strlen(temp)), "                    ",temp);
    }
    
    for (i = c->h; i < rowCount; i++) {
        sprintf(strs[3][i],"%.*s",colWidth[3],"                  ");
    }

//5th column contains hist sols
	for (i = 0; i < c->h; i++) {
		sprintf(temp,"%s",c->histSol[i]);
        sprintf(strs[4][i],"%.*s%s",(int)(colWidth[4]-strlen(temp)), "                    ",temp);
    }
    
    for (i = c->h; i < rowCount; i++) {
        sprintf(strs[4][i],"%.*s",colWidth[4],"                  ");
    }
	
//print to screen
    
    system("cls");
    
    printf("   i       Stack              Mem                            History        \n");
    printf("------------------------------------------------------------------------------\n");
    
    for (i = 0; i < rowCount; i++) {
        printf("|%s |%s | r %i -> %s |%s =%s |\n", strs[0][i], strs[1][i], i, strs[2][i], strs[3][i], strs[4][i]);
    }
    
    printf("------------------------------------------------------------------------------\n");

    printf("\nInput: ");

}
