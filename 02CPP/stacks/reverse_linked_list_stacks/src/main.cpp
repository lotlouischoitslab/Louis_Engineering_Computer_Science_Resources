#include <stdlib.h>
#include <iostream>
#include "stack.hpp"
#include <stack>
using namespace std;

/*Iterative Solution
Time - O(n) 
Space - O(1)

Recursive Solution (Implicit Stack)
Time - O(n)
Space - O(n)
*/



int main() {
    Stack louis_stack;
    Node* louis_node = nullptr;
    louis_node = louis_stack.Insert(louis_node,'L');
    louis_node = louis_stack.Insert(louis_node,'o');
    louis_node = louis_stack.Insert(louis_node,'u');
    louis_node = louis_stack.Insert(louis_node,'i');
    louis_node = louis_stack.Insert(louis_node,'s');
    louis_node = louis_stack.Insert(louis_node,' ');
    louis_node = louis_stack.Insert(louis_node,'S');
    louis_node = louis_stack.Insert(louis_node,'u');
    louis_node = louis_stack.Insert(louis_node,'n');
    louis_node = louis_stack.Insert(louis_node,'g');
    louis_node = louis_stack.Insert(louis_node,'w');
    louis_node = louis_stack.Insert(louis_node,'o');
    louis_node = louis_stack.Insert(louis_node,'o');
    louis_node = louis_stack.Insert(louis_node,' ');
    louis_node = louis_stack.Insert(louis_node,'C');
    louis_node = louis_stack.Insert(louis_node,'h');
    louis_node = louis_stack.Insert(louis_node,'o');

    Node* reversed = louis_stack.Reverse(louis_node);
    louis_stack.Print(reversed);
}