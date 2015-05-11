#include "Stack.h"
#include <stdlib.h>

#define STACKSIZE 100

struct Stack {
  int xs[STACKSIZE];
  int size;
};

Stack *newstack(){
  Stack *new = malloc(sizeof(Stack));
  new->size = 0;
  return new;
}

int size(Stack *stk) {
  return stk->size;
}

int pop(Stack *stk){
  int r = stk->xs[stk->size];
  stk->size--;
  return r;
}

void push(Stack *stk, int y){
  stk->size++;
  stk->xs[stk->size] = y;
}

int at(Stack *stk, int i) {
  return stk->xs[i];
}
