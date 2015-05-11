#include <stdlib.h>
#include "Calculator.h"
#include "Stack.h"
#include "Storage.h"

typedef int (*Compute)(Stack*);

char *keys[100];
Compute fns[100];

struct Calculator {
  Stack *stack;
  Storage *mem;
}

Calculator *newCalculator(){
  Calculator *c = malloc(sizeof(Calculator));
  c->stack = newStack();
  c->mem = newStorage();
}

void destroyCalculator(Calculator *c){
  destroyStack(c->stack);
  destroyStorage(c->mem);
  free(c);
}

void input(Calculator *c, int i){
  push(c->stack,i);
}

void compute(Calculator *c, char *sym){
  int i;
  Compute fn = NULL;
  
  for (i = 0; i < 100; i++){
    if (keys[i] == sym) {
      fn = fns[i];
      break;
    }
  }
  
  int x = fn(c->stack);
  push(c-stack,x);
}

int add(Stack* s) {
  int r = pop(s);
  int l = pop(s);
  return l + r;
}

int subtract(Stack* s) {
  int r = pop(s);
  int l = pop(s);
  return l - r;
}

int multiply(Stack* s) {
  int r = pop(s);
  int l = pop(s);
  return l * r;
}

int divide(Stack* s) {
  int r = pop(s);
  int l = pop(s);
  return l / r;
}
