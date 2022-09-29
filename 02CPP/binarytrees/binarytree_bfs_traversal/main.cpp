#include <stdlib.h>
#include <iostream>
#include <queue>

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

/*Breadth First Search (BFS): Level Order Traversal
Time Complexity = O(n)
Space Complexity = O(1) <Best> , O(n) <Worst/Average>
*/

void LevelOrder(BstNode* root) {
    if(!root) return;
    queue<BstNode*> Q;
    Q.push(root); 
    while(!Q.empty()) {
        BstNode* current = Q.front(); //front of the queue
        cout << current->data << " ";
        if(current->left) Q.push(current->left); //check if not null
        if(current->right) Q.push(current->right); //check if not null
        Q.pop(); //removing element at front
    }
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

    LevelOrder(root);
}