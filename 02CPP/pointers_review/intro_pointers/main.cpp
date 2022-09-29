#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    int n = 5;
    cout << &n << endl; //address of the int n
    int* ptr = &n; //stores the address of the n
    cout << ptr << endl;
    cout << *ptr << endl; //dereference

    *ptr = 10;
    cout << n << " : " << *ptr << endl; //n is also modified

    int v = 0;
    int* ptr2 = &v;
    *ptr2 = 7;
    cout << "v = " << v <<  " \n*ptr2 = " << *ptr2 << endl;
    

    return 0;
}