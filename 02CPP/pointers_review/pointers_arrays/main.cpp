#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    int prime_numbers[5] = {2,3,5,7,9};
    cout << prime_numbers << " : " << &prime_numbers[0] << endl; //prints the address of the prime_numbers[0]
    cout << prime_numbers[2] << endl;
    cout << *(prime_numbers+2) << endl; //add 2 more addresses an then dereference the +2 means 0 + 2

    for(int i = 0; i <=4; i++) {
        cout << "Number: ";
        cin >> prime_numbers[i];
    }

    for(int i = 0; i <=4; i++) {
        cout << *(prime_numbers +i) << " ";
    }

    return 0;
}