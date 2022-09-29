#include <stdlib.h>
#include <iostream>
#include <stack>
#include "nodes.hpp"
using namespace std;

class Stack {
    private:
      Node* head_;
      int top;
    public:
      void setName(string name);
      Node* Insert(Node* head, char data);
      void Print(Node* head);
      void Push(int x);
      void Pop();
      Node* Reverse(Node* head);
};