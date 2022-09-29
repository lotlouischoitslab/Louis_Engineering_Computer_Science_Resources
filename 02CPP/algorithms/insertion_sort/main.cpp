#include <iostream>
#include <stdlib.h>

using namespace std;

void insertion_sort(char* A, int n) {
    for(int i = 1; i < n; i++) {
        char cur = A[i];
        int j = i - 1;
        while(j>=0 && A[j] > cur) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = cur;
    }
}

int main() {
    /*Insertion Sort
    Best Case: O(n)
    Average and Worst Case: O(n^2)
    */
    char list_to_sort[8] = {'B','C','D','A','E','H','G','F'};
    insertion_sort(list_to_sort,8);
    cout << list_to_sort << endl;

    return 0;
}