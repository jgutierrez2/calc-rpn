typedef struct Calculator Calculator;

Calculator *newCalculator();

void destroyCalculator(Calculator *c);

void input(Calculator *c, int i);

void compute(Calculator *c, char *sym);

void display(Calculator *c);