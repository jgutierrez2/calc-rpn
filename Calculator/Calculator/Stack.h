typedef struct Stack Stack;

Stack *newstack();
void destroystack();
int size(Stack *stk);
int pop(Stack *stk);
void push(Stack *stk, int y);
int at(Stack *stk, int i);
