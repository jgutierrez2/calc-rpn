#include "Stack.h"
#include <stdlib.h>

#define STACKSIZE 100

struct Stack {
  double xs[STACKSIZE];
  int size;
};

Stack *newstack(){
  Stack *s = malloc(sizeof(Stack));
  s->size = 0;
  
  int i;
  for (i = 0; i < STACKSIZE; i++) {
    s->xs[i] = 0;
  }
  
  return s;
}

void destroystack(Stack *stk){
    free(stk);
}

int size(Stack *stk) {
  return stk->size;
}

int pop(Stack *stk, double *out){
  if (stk->size > 0) {
    stk->size--;
    *out = stk->xs[stk->size];
    return 1;
  }
  return 0;
}

void push(Stack *stk, double y) {
  stk->xs[stk->size] = y;
  stk->size++;
}

int at(Stack *stk, int i, double* out) {
  if (i < stk->size) {
    *out = stk->xs[i]
    return 1;
  }
  return 0;
}
