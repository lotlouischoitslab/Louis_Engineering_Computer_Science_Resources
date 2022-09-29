#include <iostream>
#include <memory>
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

int main() {
    weak_ptr<int> wePtr1;
    {
        shared_ptr<int>shPtr1 = make_shared<int>(25);
        wePtr1 = shPtr1;
        //all of the strong owners have been destroyed
    }
    
    return 0;
}