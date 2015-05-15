#include "InputInterface.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void getUserInput(char *storage) {
    scanf(" %s", storage);
}

int inArr(char **syms, int n, char *sym) {
    int i;
    for (i = 0; i < n; i++) {
        if (!strcmp(syms[i], sym)) return 1 ;
    }
    return 0;
}

void submitInput(Calculator *calc, char *in) {
    char c = *in;
    char *syms[5] = { "+", "-", "*", "/", "^" };
    
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        input(calc, atoi(in));
    }
    
    else if (inArr(syms, 5, in)) {
        compute(calc, in);
    }
    
    else if (!strcmp(in, "s")) {
        int j;
        if (scanf(" %i",&j)) storeValue(calc, j);
    }
    
    else if (!strcmp(in, "r")){
        int j;
        if (scanf(" %i",&j)) j = recallValue(calc, j);
        input(calc, j);
    }
    
    else if (!strcmp(in, "c")){
        clearStack(calc);
    }

    else if (!strcmp(in, "d")){
        deleteLast(calc);
    }
}
