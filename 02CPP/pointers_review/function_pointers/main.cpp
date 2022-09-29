#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

bool ascendingCompare(int a, int b) {
    return a < b;
}

bool descendingCompare(int a, int b) {
    return a > b;
}

void customSort(vector<int>& numbersVector, bool(*compareFuncPtr)(int,int) ) {
    for (int start_index = 0; start_index < numbersVector.size(); start_index++) {
        int best_index = start_index;

        for(int current_idx = start_index + 1; current_idx < numbersVector.size(); current_idx++) {
            //comparison algorithm
            if(compareFuncPtr(numbersVector[current_idx], numbersVector[best_index])) {
                best_index = current_idx;
            }
        }
        swap(numbersVector[start_index],numbersVector[best_index]);
    }
}

void printNumbers(vector<int>& numbersVector) {
    for(int i = 0; i < numbersVector.size(); i++) {
        cout << numbersVector[i] << " ";
    }
}


/*function pointer is used to optimize the code and code reusable*/

int main() {

    vector<int>my_numbers = {2,5,1,3,6,4};
    
    cout << "This will sort the algorithm into ascending order: ";
    bool(*funcPtr_ascend)(int,int) = ascendingCompare;
    customSort(my_numbers, funcPtr_ascend);
    printNumbers(my_numbers);

    cout << endl;

    cout << "This will sort the algorithm into descending order: ";
    bool(*funcPtr_descend)(int,int) = descendingCompare;
    customSort(my_numbers, funcPtr_descend);
    printNumbers(my_numbers);

    return 0;
}