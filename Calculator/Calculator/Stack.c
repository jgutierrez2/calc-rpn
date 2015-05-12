#include "Stack.h"
#include <stdlib.h>

#define STACKSIZE 100

struct Stack {
  int xs[STACKSIZE];
  int size;
};

Stack *newstack(){
  Stack *s = malloc(sizeof(Stack));
  s->size = 0;
  return s;
}

void destroystack(Stack *stk){
    free(stk);
}

int size(Stack *stk) {
  return stk->size;
}

int pop(Stack *stk){
  stk->size--;
  int r = stk->xs[stk->size];
  return r;
}

void push(Stack *stk, int y) {
  stk->xs[stk->size] = y;
  stk->size++;
}

int at(Stack *stk, int i) {
  return stk->xs[i];
}
