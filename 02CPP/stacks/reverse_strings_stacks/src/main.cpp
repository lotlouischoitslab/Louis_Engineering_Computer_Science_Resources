#include <stdlib.h>
#include <iostream>
#include "stack.hpp"
using namespace std;

//Time & Space Complexity = O(n)

int main() {
    //go to your reverse_strings_stacks directory using cd reverse_strings_stacks
    //type "make" in the terminal window
    //then type "./bin/exec"
    Stack louis;
    string name;
    cout << "Enter a string and substitute dash with spaces in between words i.e Louis-Sungwoo-Cho: " << endl;
    cin >> name;
    louis.setName(name);
    louis.Reverse();
    louis.Print();
}