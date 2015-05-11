#include <stdlib.h>
#include "Storage.h"

struct Storage {
  int values[10];
};

Storage *newStorage() {
  Storage *s = malloc(sizeof(Storage));
  clearStorage(s);
  return s;
}

void destroyStorage(Storage *s) {
    free(s);
}

void store(Storage *s, int i, int v) {
  s->values[i] = v;
}

int recall(Storage *s, int i) {
  return s->values[i];
}

void clearStorage(Storage *s) {
  int i;
  for ( i = 0; i < 10; i++) {
    s->values[i] = 0;
  }
}
