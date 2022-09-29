#include <singularlylinkedlist.hpp>

SLinkedList::SLinkedList(): head_(nullptr) {}; //constructor

SLinkedList::~SLinkedList() { //destructor
    while(!empty()) removeFront();
}

bool SLinkedList::empty() const { //is list empty?
    return head_ == nullptr;
}

const string& SLinkedList::front() const { //get front element
    return head_->elem;
}

void SLinkedList::addFront(const string& e) {
    StringNode* insert = new StringNode;
    insert->elem = e;
    insert->next = head_;
    head_ = insert;
}

void SLinkedList::insert(const string& e, int idx) {
    StringNode* insert = new StringNode;
    insert->elem = e;
    if(idx == 0) {
        addFront(e);
        return;
    } else {
        StringNode* current = head_;
        int count = 1;
        while(count != idx) {
            current = current->next;
            count++;
        }
        insert->next = current->next;
        current->next = insert;
    }
}

void SLinkedList::removeFront() {
    StringNode* old = head_;
    head_ = old->next;
    delete old;
}

void SLinkedList::remove(int idx) {
    if (head_ == nullptr) {
        return;
    } else if(idx == 0) {
        removeFront();
        return;
    }
    //Find previous node of the node to be removed
    StringNode* current = head_;
    for (int i = 0; current != nullptr && i < idx - 1; i++) {
        current = current->next;
    }

    StringNode* next = current->next->next;
    delete current->next;
    current->next = next;
}

 ostream& operator<<(ostream& out, const SLinkedList& s) { 
    StringNode* current = s.get_head();
    if(current) {
        out << "|" << current->elem << "| -> ";
        current = current->next;
    } else {
        out << "Empty";
        return out;
    }
    //Traverse until the end of the linked list
    while(current != nullptr) {
        out << "|" << current->elem << "| -> ";
        current = current->next;
    }
    
    return out;
    }

