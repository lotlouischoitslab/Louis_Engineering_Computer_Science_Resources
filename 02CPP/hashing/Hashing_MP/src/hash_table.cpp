#include "hash_table.hpp"
        
HashTable::HashTable(int size) : BUCKET(size) , table(new list<int>[BUCKET]) {};

void HashTable::insert(int key) {
    int idx = hashing(key);
    table[idx].push_back(key);
}

void HashTable::remove(int key) {
    // get the hash index of key
  int index = hashing(key);
 
  // find the key in (index)th list
  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }
 
  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}

bool HashTable::search(int data) {
    int key = hashing(data);
    for(list<int> :: iterator i = table[key].begin(); i != table[key].end(); i++) {
        if(*i == key) {
            return true;
        }
    }
    return false;
}

void HashTable::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}