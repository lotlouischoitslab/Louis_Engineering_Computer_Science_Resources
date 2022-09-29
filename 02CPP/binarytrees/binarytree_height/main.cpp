#include <stdlib.h>
#include <iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

/* Height of node = Number of edges in longest path from node to leaf node 
   Height of tree = Height of root
   Height of tree with 1 node = 0
   Depth of a node = number of edges in path from root to that node
*/

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

int FindHeight(BstNode* root) {
    if (!root) return -1;
    return max(FindHeight(root->left),FindHeight(root->right)) + 1;
}


int main() {
    BstNode* root = nullptr; //create an empty tree
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

    cout << "Height: " << FindHeight(root) << endl;
}