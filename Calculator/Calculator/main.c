#include <stdio.h>
#include <stdlib.h>
#include "InputInterface.h"

typedef struct String { char str[150]; } String;

Calculator *calc;



void next(Calculator *calc){
    char store[50];
    getUserInput(store);
    submitInput(calc, store);
    display(calc);
}

int main(){
    calc = newCalculator(submitInput);

    display(calc);
    
    while (1) {
        next(calc);
    }
}