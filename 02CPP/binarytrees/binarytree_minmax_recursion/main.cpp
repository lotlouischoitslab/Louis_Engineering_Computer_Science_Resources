#include <stdlib.h>
#include <iostream>

using namespace std;

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

int FindMin(BstNode* root) { //left subtree
    BstNode* current = root;
    if(!root) {
        cout << "Runtime Error: Tree is empty" << endl;
        return -1;
    } else if(root->left == nullptr) { //base case for exit recursion
        return root->data;
    }
    return FindMin(root->left); //recursively call the function
}

int FindMax(BstNode* root) { //right subtree
    BstNode* current = root;
    if(!root) {
        cout << "Runtime Error: Tree is empty" << endl;
        return -1;
    } else if(root->right == nullptr) { //base case for exit recursion
        return root->data;
    }
    return FindMin(root->right); //recursively call the function
}


int main() {
    BstNode* root = nullptr; //create an empty tree
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

    cout << "Maximum value: " << FindMax(root) << endl;
    cout << "Minimum value: " << FindMin(root) << endl;
}