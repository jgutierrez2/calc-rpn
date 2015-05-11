#include <stdlib.h>
#include "Calculator.h"
#include "Stack.h"
#include "Storage.h"



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
  int r = pop(c->stack);
  int l = pop(c->stack);
  
}

int add(int l, int r) {
  return l + r;
}

int subtract(int l, int r) {
  return l - r;
}

int multiply(int l, int r) {
  return l * r;
}

int divide(int l, int r) {
  return l / r;
}
