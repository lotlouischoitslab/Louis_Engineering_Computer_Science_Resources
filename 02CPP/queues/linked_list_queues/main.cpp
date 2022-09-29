#include <iostream>
#include <stdlib.h>

using namespace std;
/* Queue ADT
A list or collection with the restriction that insertion can be performed at one
end (rear) and deletion can be performed at the other end (front)

Operations: All constant time O(1)
(1) EnQueue(x) O(n)
(2) DeQueue() O(1)
(3) front()
(4) IsEmpty()
*/

/*Linked List Implementation*/
struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void EnQueue(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    if(!front && !rear) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
} 

void DeQueue() {
    Node* temp = front;
    if(!front) return;
    if(front == rear) front = rear = nullptr;
    else front = front->next;
    delete temp;
}

void print() {
    while(front != rear) {
        cout << front->data << " ";
        front = front->next;
    }
    cout << front->data << " ";
}

int main() {
    EnQueue(1);
    EnQueue(2);
    EnQueue(3);
    EnQueue(4);
    EnQueue(5);
    EnQueue(6);

    // print();

    // cout << endl << "End" << endl;

    EnQueue(7);
    DeQueue();
    DeQueue();
    print();

}