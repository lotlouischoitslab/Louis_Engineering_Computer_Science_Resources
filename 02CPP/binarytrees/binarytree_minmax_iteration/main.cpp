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

int FindMin(BstNode* root) {
    BstNode* current = root;
    if(!root) {
        cout << "Runtime Error: Tree is empty" << endl;
        return -1;
    }
    while(current->left != nullptr) {
        current = current->left; //traverse to the left side
    }
    return current->data; //return the minimum value
}

int FindMax(BstNode* root) {
    BstNode* current = root;
    if(!root) {
        cout << "Runtime Error: Tree is empty" << endl;
        return -1;
    }
    while(current->right != nullptr) {
        current = current->right; //traverse to the right side
    }
    return current->data; //return the maximum value
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