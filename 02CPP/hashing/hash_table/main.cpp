#include "hashTable.hpp"
#include <iostream>
#include <string>

using namespace std;
int main() {
    HashTable h;
    cout << h.isEmpty() << endl;

    HashTable addresses;
    addresses.insertItem(904, "Louis Sungwoo Cho");
    addresses.insertItem(905, "Juyoung Choi");
    addresses.insertItem(906, "Peter Hakyung Yun");
    addresses.insertItem(907, "Sangyun Lee");
    addresses.insertItem(908, "Jenny Wenyi Chen");
    addresses.insertItem(909, "Emma Yue Hu");

    addresses.printTable();

    // addresses.removeItem(904);

    // addresses.printTable();


}