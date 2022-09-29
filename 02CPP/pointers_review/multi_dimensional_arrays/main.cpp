#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int rows, cols;
    cout << "rows, cols:";
    cin >> rows >> cols;

/*Creating a new 2d array*/
    int **table = new int*[rows];

    for(int i = 0; i < rows; i++) {
        table[i] = new int[cols];
    }
/*Deleting a 2d array*/

   for(int i = 0; i < rows; i++) {
    delete[] table[i];
   }

   delete[] table;
   table = nullptr;

   return 0;
}