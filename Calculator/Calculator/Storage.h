typedef struct Storage Storage;

Storage *newStorage();

void destroyStorage(Storage*);

void store(Storage*, int, int);

int recall(Storage*, int);

void clearStorage(Storage*);
