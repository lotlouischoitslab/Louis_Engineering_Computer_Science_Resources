#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

class Stack {
    private:
      string name_;
      int top;
    public:
      void setName(string name);
      void Print();
      void Push(int x);
      void Pop();
      void Reverse();
      string return_Reverse();
      int Top();
      bool IsEmpty();

};