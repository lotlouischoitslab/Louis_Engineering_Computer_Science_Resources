#define BINARYTREES_HPP
#ifdef BINARYTREES_HPP
#include <stdlib.h>
#include <iostream>
#include "nodes.hpp"
#include <algorithm>
#include <queue>
using namespace std;

class BinaryTrees {
  public:
    BinaryTrees();
    BinaryTrees(Node* rootNode);
    BinaryTrees(int* array, int size);
    int Height(Node* root); //Height of the binary tree
    int maxDepth(Node* node); //Maximum Depth of binary tree
    int minDepth(Node* node); //Minimum Depth of binary tree
    Node* get_root() const { return root_; }
    Node* FindMin(); //Find the minimum value node
    Node* FindMax(); //Find the maximum value node
    Node* FindMin_helper(Node* current); //Find the minimum value node helper 
    Node* FindMax_helper(Node* current); //Find the maximum value node helper 
    void insert(int value); //Insert a value in a binary tree
    Node* insert_helper(Node* root,int value); //Helper function for insert a node in binary tree
    void delete_tree(); //Delete Entire Tree
    void delete_tree_helper(Node* &node); //Helper function for delete entire tree
    void delete_node(int value); //Delete a node in a binary tree
    Node* delete_node_helper(Node* node, int value); //Helper function for delete node in binary tree
    void pre_order(Node* current);
    void in_order(Node* current);
    void post_order(Node* current);
    void LevelOrder();
    void LevelOrder_helper(Node* &root);
    void Display(Node* root);

    bool IsSubtreeLesser(Node* root, int value);
    bool IsSubtreeGreater(Node* root, int value);
    bool IsBinarySearchTree(Node* root);
    bool IsBinarySearchTree(Node* root, int minValue, int maxValue);

    int count_nodes(Node* node);

    void Heapify(int* arr, int size, int i);
    void HeapSort();

    void print_array();

  private:
    Node* root_;
    int* array_;
    int size_of_array_;
};

#endif