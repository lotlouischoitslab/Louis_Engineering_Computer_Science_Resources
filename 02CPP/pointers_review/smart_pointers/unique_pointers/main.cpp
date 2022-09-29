#include <iostream>
#include <stdlib.h>
#include <memory>
#include <vector>

using namespace std;

class MyClass {
 public:
    MyClass() {
        cout << "Constructor invoked" << endl;
    }

    ~MyClass() {
        cout << "Destructor invoked" << endl;
    }
};


//unique pointers cannot be shared
int main() {
    // unique_ptr<int>unPtr1 = make_unique<int>(25);
    // //unique_ptr<int>unPtr2 = unPtr1; DO NOT ATTEMPT THIS BECAUSE YOU CANNOT SHARE UNIQUE POINTERS

    // //But you can move the ownership. Think about copyright laws of who owns what
    // unique_ptr<int>unPtr2 = move(unPtr1);
    // cout << "ownership is: " <<  *unPtr2 << endl; //remember that the ownership is now unPtr2
    // cout << "unPtr1 becomes: " << *unPtr1 << endl; //remember that unPtr1 is now nullptr

    cout << "Testing the constructor " << endl;
    {
    unique_ptr<MyClass> unPtr1 = make_unique<MyClass>();
    }


    //cout << *unPtr1 << endl; //dereference the pointer


    return 0;
}

