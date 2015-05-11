#include <stdlib.h>
#include "Calculator.h"
#include "Stack.h"
#include "Storage.h"

struct Calculator {
  Stack stack;
  Storage mem;
}

Calculator *newCalculator(){
  Calculator *c = malloc(sizeof(Calculator));
  c->stack = newStack();
  c->mem = newStorage();
}

void destroyCalculator(Calculator *c){
  destroyStack(c->stack);
  destroyStorage(c->Storage);
  free(c);
}

void input(Calculator *c, int i){
  push(c->stack,i);
}

void compute(Calculator *c, char *sym){
  
}
