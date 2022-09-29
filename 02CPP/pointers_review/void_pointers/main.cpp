#include <stdlib.h>
#include <iostream>

using namespace std;

void printNumber(int* numberPtr) { //the parameter is an address
    cout << *numberPtr << endl;
}

void printLetter(char* charPtr) { //the parameter is an address
    cout << *charPtr << endl;
}

void print(void* ptr, char type) { //point to variable of any data type
    switch(type) {
        case 'i': cout << *((int*) ptr) << endl; break;//handle int*
        case 'c': cout << *((char*) ptr) << endl; break; //handle char*
    }
}

int main() {
    int number = 5;
    char letter = 'a';
    // printNumber(&number);
    // printLetter(&letter);
    print(&number, 'i');
    print(&letter, 'c');

    return 0;
}