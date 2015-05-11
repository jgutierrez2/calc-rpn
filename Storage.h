typedef struct Storage Storage;

Storage *newStorage();

void store(Storage *s, int i, int v);

int recall(Storage *s, int i);

void clear(Storage *s);
