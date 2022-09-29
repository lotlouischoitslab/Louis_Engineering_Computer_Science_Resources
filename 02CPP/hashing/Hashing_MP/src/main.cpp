#include "hash_table.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

/*Time Complexity: 
Search : O(1+(n/m))
Delete : O(1+(n/m))
n = number of slots in hash HashTable
m = number of keys to be inserted
*/

int main() {
    HashTable* h = new HashTable(7);
    int a[] = {15,11,27,8,12};
    int* ptr = a;
    for(int i =0 ; i < 7; i++) {
        h->insert(ptr[i]);
    }

    h->remove(12);

    h->displayHash();

    cout << "Find: " << h->search(10) << endl;

    return 0;
}