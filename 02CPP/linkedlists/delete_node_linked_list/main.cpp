#include <stdlib.h>
#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
};

struct Node* head;

void Insert(int data) {
    Node* temp = new Node(); //create new node
    temp->data = data; //store the data
    temp->next = nullptr; //set the next temp to nullptr
    if(head != nullptr) temp->next = head;
    head = temp;
}

void Print(Node* temp) {
    while(temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void Delete(int n) {
    Node* temp1 = head;
    if(n == 1) {
        head = temp1->next;
        delete temp1;
        return;
    }
    for(int i = 0; i < n-2; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next; //nth Node
    temp1->next = temp2->next; //n+1th Node
    delete temp2;
}


int main() {
    head = nullptr; //empty list
    Print(head);
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); //List: 2,4,6,5
    Print(head);
    int n;
    printf("Enter a position\n");
    scanf("%d",&n);
    Delete(n);
    Print(head);
}