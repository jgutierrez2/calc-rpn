#include <stdlib.h>
#include "Storage.h"

struct Storage {
  int values[10];
}

Storage *newStorage() {
  Storage *s = malloc(sizeof(Storage));
  clear(s);
  return s;
}

void store(Storage *s, int i, int v) {
  s->values[i] = v;
}

int recall(Storage *s, int i) {
  return s->values[i];
}

void clear(Storage *s) {
  int i;
  for ( i = 0; i < 10; i++) {
    s->values[i] = 0;
  }
}
