#include "InputTypes.h"
#include <stdio.h>

Type type(char *s){
  char c = *s;

  if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
    return Num;
  }
  else if (c == '+' || c == '-' || c == '/' || c == '*') {
    return Sym;
  }
  else {
    return Err;
  }
}

Type getInput(char *storage, int maxStorage) {
  fgets(storage, maxStorage, stdin);
  return type(storage);
}
