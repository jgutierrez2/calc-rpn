typedef struct Calculator Calculator;

Calculator *newCalculator(void (*interface)(Calculator*, char*));

void destroyCalculator(Calculator *c);

void input(Calculator *c, int i);

void compute(Calculator *c, char *sym);

void clearStack(Calculator *c); 

void deleteLast(Calculator *c); 

void display(Calculator *c);

void storeValue(Calculator *c, int i);

int recallValue(Calculator *c, int i);

void record(Calculator *c);

void endRec(Calculator *c);

void run(Calculator *c);
