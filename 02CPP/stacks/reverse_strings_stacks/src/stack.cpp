#include "stack.hpp"

void Stack::setName(string name) {
    name_ = name;
}

void Stack::Reverse() {
    stack<char> S;
    //loop for push
    for(size_t i = 0; i < name_.length(); i++) {
        S.push(name_.at(i));
    }

    //loop for pop
    for(size_t i = 0; i < name_.length(); i++) {
        name_.at(i) = S.top(); //overwrite the string at index i.
        S.pop(); //perform pop
    }
}

string Stack::return_Reverse() {
    stack<char> S;
    //loop for push
    for(size_t i = 0; i < name_.length(); i++) {
        S.push(name_.at(i));
    }

    //loop for pop
    for(size_t i = 0; i < name_.length(); i++) {
        name_.at(i) = S.top(); //overwrite the string at index i.
        S.pop(); //perform pop
    }
    return name_;
}

void Stack::Print() {
    for(size_t i = 0; i < name_.length(); i++) {
        cout << (name_.at(i));
    }
    cout << endl;
}

