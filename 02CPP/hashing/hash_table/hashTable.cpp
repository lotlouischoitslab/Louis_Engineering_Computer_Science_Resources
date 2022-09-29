#include "hashTable.hpp"

bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashGroups; i++) {
        sum+=table[i].size();
    }
    if(!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bltr = begin(cell);
    bool keyExists = false;
    for(; bltr != end(cell); bltr++) {
        if(bltr->first== key) {
            keyExists = true;
            bltr->second = value; 
            cout << "[WARNING] Key exists: Value replaced." << endl;
            break;
        }
    }

    if(!keyExists) {
        cell.emplace_back(key,value);
    }
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bltr = begin(cell);
    bool keyExists = false;
    for(; bltr != end(cell); bltr++) {
        if(bltr->first== key) {
            keyExists = true;
            bltr = cell.erase(bltr); 
            cout << "[WARNING] Key exists: Value replaced." << endl;
            break;
        }
    }
    if (!keyExists) {
        cout << "[WARNING] Key not found. Pair not removed." << endl;
    }

}

void HashTable::printTable() {
    for(int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;
        auto bltr = table[i].begin();
        for(; bltr != table[i].end(); bltr++) {
            cout << "[INFO] Key: " << bltr->first << " Value: " << bltr->second << endl;
        }
    }
    return;
}




