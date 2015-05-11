#include <stdlib.h>
#include <math.h>
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
  if (*sym == '+' || *sym == '-' || *sym == '*' || *sym == '/' || *sym == '^') {
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
