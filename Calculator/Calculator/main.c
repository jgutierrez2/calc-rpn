#include <stdio.h>
#include <stdlib.h>
#include "InputTypes.h"
#include "Calculator.h"

typedef struct String { char str[150]; } String;

Calculator *calc;



void next(Calculator *calc){
    char in[50];
    Type t = getInput(in,50);
    
    switch (t) {
        case Num: {
            input(calc, atoi(in));
            break;
        }
        case Sym: {
            compute(calc, in);
            break;
        }
        default : {
            break;
        }
    }
    
    display(calc);
}

int main(){
    calc = newCalculator();

    display(calc);
    
    while (1) {
        next(calc);
    }
}