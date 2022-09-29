#include <iostream>
#include <list>
#include <string>
using namespace std;

//Hashtable to implement 904 Louis

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int,string>> table[hashGroups]; //list 1, index 0 index 1 index 2 index

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key); //each key is distinct
        string searchTable(int key);
        void printTable();
};