#include<stdlib.h>
#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* Insert(Node* head, int data) {
    Node* temp = new Node(); //create new node
    temp->data = data; //store the data
    temp->next = nullptr; //next pointer is set to nullptr
    if(head == nullptr) head = temp;
    else {
        Node* temp1 = head;
        while(temp1->next != nullptr) temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

Node* Reverse(Node* head) {
    if (head->next == nullptr) return head;
    
    Node* rest = Reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

void Forward_Print(Node* head) { //accepts a head node
    if(head == nullptr) return;
    cout << head->data << " ";
    Forward_Print(head->next); //Recursive Call
}

void Reverse_Print(Node* p) {
    if(p == nullptr) return;
    Reverse_Print(p->next); //Recursive Call
    cout << p->data << " ";
}


int main() {
    Node* head_ = nullptr;  //list is empty
    head_ = Insert(head_,1); //insert the new node 
    head_ = Insert(head_,2); //insert the new node 
    head_ = Insert(head_,3); //insert the new node 
    Forward_Print(head_);
    cout << endl;
    Reverse_Print(head_);
    ///////////////////////////////////////////////////////////////////////

    Node* reversed_head_ = nullptr; //list is empty
    reversed_head_ = Insert(reversed_head_,2); //insert the new node 
    reversed_head_ = Insert(reversed_head_,6); //insert the new node 
    reversed_head_ = Insert(reversed_head_,5); //insert the new node 
    reversed_head_ = Insert(reversed_head_,4); //insert the new node 
    cout << endl;
    
    Forward_Print(reversed_head_);
    cout << endl;
    reversed_head_ = Reverse(reversed_head_);
    Forward_Print(reversed_head_);
    cout << endl;
}