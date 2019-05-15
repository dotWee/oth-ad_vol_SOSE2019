# Aufgabe 4 (Hashing mit offener Adressierung)

## a)

Lineares Sondieren:

```c++
void put_lin(int key, int value) {
    int hash = (key % tableSize);
    while (table[hash] != NULL && table[hash]->getKey() != key)
    hash = (hash + 1) % tableSize;
    if (table[hash] != NULL)
        delete table[hash];
        table[hash] = new HashEntry(key, value);
}
```

Quadratisches Sondiern:

```c++
void put_quad(int key, int value) {
    int hash = (key % tableSize);
    int i = 1;

    while (table[hash] != NULL && table[hash]->getKey() != key)
        hash = (hash + (-1)^(i + 1) * (i / 2)^2) % tableSize;
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
}
```