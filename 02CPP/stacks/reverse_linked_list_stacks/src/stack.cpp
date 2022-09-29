#include "stack.hpp"

Node* Stack::Insert(Node* head, char data) {
    head_ = head;
    Node* temp = new Node(); //create new node
    temp->data = data; //store the data
    temp->next = nullptr; //next pointer is set to nullptr
    if(head_ == nullptr) head_ = temp;
    else {
        Node* temp1 = head_;
        while(temp1->next != nullptr) temp1 = temp1->next;
        temp1->next = temp;
    }
    return head_;
}

Node* Stack::Reverse(Node* head) {
    // Stack to store elements of list
    stack<Node *> stk;
 
    // Push the elements of list to stack
    Node* ptr = head;
    while (ptr->next != NULL) {
        stk.push(ptr);
        ptr = ptr->next;
    }
 
    // Pop from stack and replace
    // current nodes value'
    head = ptr;
    while (!stk.empty()) {
        ptr->next = stk.top();
 
        ptr = ptr->next;
        stk.pop();
    }
     
    ptr->next = NULL;
     
    return head;
}

void Stack::Print(Node* head_) {
    if(head_ == nullptr) return;
    cout << head_->data << " ";
    Print(head_->next); //Recursive Call
}

