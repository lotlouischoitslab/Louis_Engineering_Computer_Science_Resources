// C++ program for the above approach
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
// Function to check whether string
// is palindrome
string isPalindrome(string* input)
{
    string S = *input;
    transform(S.begin(),S.end(),S.begin(), ::tolower); //to lowercase
    transform(S.begin(),S.end(), S.begin(), ::toupper); //tp uppercase
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++) {
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return "No";
        }
    }
    // Return "Yes"
    return "Yes";
}

// Driver Code
int main()
{
    string ex1 = "ABCDCBA";
    string* name1 = &ex1;
    cout << "Check status: " << isPalindrome(name1) << endl;

    string ex2 = "Louis";
    string* name2 = &ex2;
    cout << "Check status: " << isPalindrome(name2) << endl;

    string ex3 = "Dad";
    string* name3 = &ex3;
    cout << "Check status: " << isPalindrome(name3) << endl;

    string ex4 = "Mom";
    string* name4 = &ex4;
    cout << "Check status: " << isPalindrome(name4) << endl;

    string ex5 = "UIUC";
    string* name5 = &ex5;
    cout << "Check status: " << isPalindrome(name5) << endl;
 
    return 0;
}