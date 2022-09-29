#include <iostream>
#include <stdlib.h>

using namespace std;

string reverseString(string input) {
    if(input == ""){ //base case
        return "";
    }

    //recursive case
    return reverseString(input.substr(1)) + input.at(0);
}

int main() {
    string input;
    cout << "Enter a word to reverse print: ";
    cin >> input;
    string output = reverseString(input);
    cout << output << endl;
}