#ifndef HASHMAP__H
#define HASHMAP__H

#include <cstdio>
#include <iostream>

using namespace std;

class HashEntry {
private:
      int key;
      int value;
public:
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }
 
      int getKey() {
            return key;
      }
 
      int getValue() {
            return value;
      }
};
 
class HashMap {
private:
      HashEntry **table;
      int tableSize;
public:
      HashMap(int size) {
          tableSize = size;
            table = new HashEntry*[tableSize];
            for (int i = 0; i < tableSize; i++)
                  table[i] = NULL;
      }
 
      int get(int key) {
            int hash = (key % tableSize);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + 1) % tableSize;
            if (table[hash] == NULL)
                  return -1;
            else
                  return table[hash]->getValue();
      }

      void put_lin(int key, int value) {
            int hash = (key % tableSize);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + 1) % tableSize;
            if (table[hash] != NULL)
                  delete table[hash];
            table[hash] = new HashEntry(key, value);
      }  

      void put_quad(int key, int value) {
            int hash = (key % tableSize);
            int i = 1;

            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + (-1)^(i + 1) * (i / 2)^2) % tableSize;
            if (table[hash] != NULL)
                  delete table[hash];
            table[hash] = new HashEntry(key, value);
      }
 
      ~HashMap() {
            for (int i = 0; i < tableSize; i++)
                  if (table[i] != NULL)
                        delete table[i];
            delete[] table;
      }
};

#endif // HASHMAP__H