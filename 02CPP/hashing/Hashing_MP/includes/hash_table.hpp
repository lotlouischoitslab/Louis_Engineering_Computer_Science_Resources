#define HASH_TABLE_HPP
#ifdef HASH_TABLE_HPP
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <list>
using namespace std;

class HashTable {
      int BUCKET = 1;
      list<int>*table;
    public:
        HashTable(int size);
        int hashing(int data) {
            return data % BUCKET;
        }
        void insert(int data);
        void remove(int key);
        bool search(int data);
        void displayHash();
};


#endif