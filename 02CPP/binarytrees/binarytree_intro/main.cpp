#include <stdlib.h>
#include <iostream>

using namespace std;

/////From discrete mathematics, remember that a tree with N nodes have N-1 edges
/////Depth of x is length of path from root to x
/////Number of edges in path from root to x
/////Height of x is number of edges in longest path from x to leaf
//////Applications of Trees
//// 1) Storing naturally hierarchal data-> e.g file system
//// 2) Organize data for quick search, insertion, deletion
//// 3) Dictionary
//// 4) Network Routing Algorithm (Think about Intelligent Transportation Systems (ITS)) Louis' favorite field in Civil and Environmental Engineering

////Binary Tree each node can have at most 2 children
/////max n.o of nodes at level i is 2^i
///max n.o of nodes in a tree with height h nodes = 2^(h+1) - 1
///height = log2(n+1) -1 or floor of [log2n]

////1) Dynamically created nodes
////2) Arrays

/////Arrays             Linkedlist                   Sorted Array     BST (Balanced)
/////Search(x) O(n)     O(n)                         O(logn)            O(logn)
/////Insert(x) O(1)     O(1) (head) O(n) (tail)      O(n)               O(logn)
/////Remove(x) O(n)     O(1) (head) O(n) (tail)      O(n)               O(logn)

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

BstNode* Insert(BstNode* root, int data) {
    if (root == nullptr) { //check if the root is nullptr
        root = GetNewNode(data); //make the node in the root position
        return root;
    } else if (data <= root->data) { //we are going to go left first
        root->left = Insert(root->left,data);  //recursively call the left side
    } else { 
        root->right = Insert(root->right,data); //recursively call the right side
    }
    return root; //return the root
}

bool Search(BstNode* root, int data) {
    if(root == nullptr) return false; //check if the root is nullptr
    else if(root->data == data) return true; //return true if found
    else if(data <= root->data) return Search(root->left,data); //recursively call the left side
    else return Search(root->right,data); //recursively call the right side
}

int main() {
    BstNode* root = nullptr; //create an empty tree
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

    int number;
    cout << "Enter a number to be searched" << endl;
    cin >> number;
    if(Search(root,number)) cout << "Found" << endl;
    else cout << "Not Found" << endl;
}