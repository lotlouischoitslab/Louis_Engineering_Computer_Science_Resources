#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include <stdlib.h>
#include <iostream>
#include <stringnode.hpp>
using namespace std;

class SLinkedList {
    public:
      SLinkedList();
      ~SLinkedList();
      bool empty() const;
      const string& front() const;
      void addFront(const string& e);
      void removeFront();
      void insert(const string& e, int idx);
      void remove(int idx);
      StringNode* get_head() const {return head_; }
    private:
      StringNode* head_;
};

ostream& operator<<(ostream& out, const SLinkedList& s);

#endif