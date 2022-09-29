#include<stdio.h>
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
    Node* next;
    Node* current = head;
    Node* prev = nullptr;
    while(current !=nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
 return head;
}

void Print(Node* head) { //accepts a head node
    while(head != nullptr) {
        cout << head->data << " "; //prints out the node
        head = head->next; //continue traversing through
    }
    cout << endl;
}

int main() {
    Node* head_ = nullptr;  //list is empty
    head_ = Insert(head_,1); //insert the new node 
    head_ = Insert(head_,2); //insert the new node 
    head_ = Insert(head_,3); //insert the new node 
    
    Print(head_); //prints the front node
    Node* reversed = nullptr;
    reversed = Reverse(head_); //reverse the head
    Print(reversed); //prints the reversed linked list
}