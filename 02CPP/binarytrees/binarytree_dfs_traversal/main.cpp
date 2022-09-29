#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

/* Time Complexity: O(n)
   Space Complexity: O(n)
   Worst: O(n)
   Best/Average: O(logn)
*/


/*  Pre-Order: <root> <left> <right>
    1) Visit root 
    2) Visit left sub-tree
    3) Visit right sub-tree
*/

void PreOrder(BstNode* root) {
    if(!root) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

/*  In-Order: <left> <root> <right> 
    1) Visit left sub-tree
    2) Visit root
    3) Visit right sub-tree
*/

void InOrder(BstNode* root) {
    if(!root) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

/*  Post-Order <left> <right> <root>
    1) Visit left sub-tree
    2) Visit right sub-tree
    3) Visit root 
*/

void PostOrder(BstNode* root) {
    if(!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}


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

int main() {
    BstNode* root = nullptr; //create an empty tree
    root = Insert(root,15);

    root = Insert(root,10);
    root = Insert(root,20);
    
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,17);
    root = Insert(root,25);

    root = Insert(root,4);
    root = Insert(root,9);
    root = Insert(root,19);

    root = Insert(root,18);

    ///Pre-Order Traversal
    cout << "Pre-Order Traversal: " << endl;
    PreOrder(root);

    cout << endl;
    ///In-Order Traversal
    cout << "In-Order Traversal" << endl;
    InOrder(root);

    cout << endl;
    ///Post-Order Traversal
    cout << "Post-Order Traversal" << endl;
    PostOrder(root);
}