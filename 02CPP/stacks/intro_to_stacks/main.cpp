#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX_SIZE 101

/*Stacks: 
Definition: A list with the restriction that insertion and deletion can be performed
only from one end called top (Last In First Out (LIFO)).
- Think about an elevator with full capacity
- Tower of Hanoi Algorithm from CS 173 and potentially CS 374
- Pile of plates
- Tennis ball container

Abstract Data Type : Only consider the features or mathematical model NOT the implementation

Operations:
Time Complexity: O(1) Constant Time
(1) Push : Insert or push onto the stack
(2) Pop : Remove most recent item from stack
(3) Top : Returns top of the element stack
(4) IsEmpty() : Check if the stack is empty or not

Applications: 
- Function Calls/ Recursions
- Undo Operations in editor ctrl + z

Array Implementation O(1)
    int A[10];
    top <- -1 empty stack
    push(x) top++ then fill in A[top] <- x
    overflow is O(n) for overflow array
    push O(1) - best case 
    push O(n) - worst case
    push O(1) - average case */

int A[MAX_SIZE];
int top = -1;

/* Array Stack Functions*/
void Push(int x) {
    if(top == MAX_SIZE-1) {
        cout << "Error: Stack overflow" << endl;
        return;
    }
    A[++top] = x; //increment will happen before assignment
}

void Pop() {
    if(top == -1) {
        cout << "No element to remove" << endl;
        return;
    }
    top--;
}

void Print() {
    cout << "Array Stack: ";
    for(int i = 0; i <= top; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
////////////////////////////////////////////////

/*Linked List Stack Functions*/

struct Node {
    int data;
    Node* link;
};

Node* top_link = nullptr;

void link_Push(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->link = top_link;
    top_link = temp;
}

void link_Pop() {
    Node* temp;
    if(top_link == nullptr) return;
    temp = top_link;
    top_link = top_link->link;
    delete temp;
}

void link_Print() {
    cout << "Linked List Stack: ";
    Node* current = top_link;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}

int main() {
    /*Array Implementation of Stacks*/
    cout << "Array Implementation of Stacks" << endl;
    Push(2); Print();
    Push(5); Print();
    Push(10); Print();
    Pop(); Print();
    Push(12); Print();
    cout << endl;
    ////////////////////////////////////////////////////////////////

    /*Linked List Implementation of Stacks*/
    /*Insert/Delete
    - at the end of the list (tail) O(n)
    - at the beginning of the list (head) O(1)
    */

    cout << "Linked List Implementation of Stacks" << endl;
    link_Push(2); link_Print();
    link_Push(5); link_Print();
    link_Push(10); link_Print();
    link_Pop(); link_Print();
    link_Push(12); link_Print();
}