#define NODES_HPP
#ifdef NODES_HPP
#include <stdlib.h>
#include <iostream>

class Node {
  public:
    Node() = default;
    Node(int value) : value(value), left(nullptr), right(nullptr) {};
    int value;
    Node* left;
    Node* right;
    
};

#endif