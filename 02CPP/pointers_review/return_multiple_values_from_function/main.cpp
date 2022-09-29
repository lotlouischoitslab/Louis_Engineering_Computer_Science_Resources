#include <stdlib.h>
#include <iostream>

using namespace std;

int get_min(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if(numbers[i] < min) min = numbers[i];
    }
    return min;
} 

int get_max(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if(numbers[i] > max) max = numbers[i];
    }
    return max;
} 

void getMinMax(int numbers[], int size, int* min, int* max) {
    for (int i = 1; i < size; i++) {
        if(numbers[i] > *max) *max = numbers[i];
        if(numbers[i] < *min) *min = numbers[i];
    }
}

int main() {
    int numbers[5] = {5,4,3,2,1};
    cout << "Minimum is " << get_min(numbers, 5) << endl;
    cout << "Maximum is " << get_max(numbers, 5) << endl;

    int min = numbers[0];
    int max = numbers[0];

    cout << endl;
    cout << "Test case for getMinMax function:" << endl;

    getMinMax(numbers,5,&min,&max);
    cout << "Minimum is " << min << endl;
    cout << "Maximum is " << max << endl;

    return 0;
}