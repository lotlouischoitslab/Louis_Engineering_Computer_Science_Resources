#include <stdlib.h>
#include <iostream>
#include "binarytrees.hpp"
using namespace std;

int main() {
    Node* n1 = new Node(50);
    Node* n2 = new Node(76);
    Node* n3 = new Node(21);
    Node* n4 = new Node(4);
    Node* n5 = new Node(32);
    Node* n6 = new Node(64);
    Node* n7 = new Node(15);
    Node* n8 = new Node(52);
    Node* n9 = new Node(14);
    Node* n10 = new Node(100);
    Node* n11 = new Node(83);
    Node* n12 = new Node(2);
    Node* n13 = new Node(3);
    Node* n14 = new Node(70);
    Node* n15 = new Node(87);
    Node* n16 = new Node(80);

    BinaryTrees* b1 = new BinaryTrees();
    b1->insert(n1->value);
    b1->insert(n2->value);
    b1->insert(n3->value);
    b1->insert(n4->value);
    b1->insert(n5->value);
    b1->insert(n6->value);
    b1->insert(n7->value);
    b1->insert(n8->value);
    b1->insert(n9->value);
    b1->insert(n10->value);
    b1->insert(n11->value);
    b1->insert(n12->value);
    b1->insert(n13->value);
    b1->insert(n14->value);
    b1->insert(n15->value);
    b1->insert(n16->value);

    cout << "Is Binary Tree? : " << b1->IsBinarySearchTree(b1->get_root()) << endl;

    int height = b1->Height(b1->get_root());
    cout << "Height of the Binary Tree: " << height << endl;

    int max = b1->maxDepth(b1->get_root());
    cout << "Maximum Depth of the Binary Tree: " << max << endl;

    int min = b1->minDepth(b1->get_root());
    cout << "Minimum Depth of the Binary Tree: " << min << endl;

    int nodes = b1->count_nodes(b1->get_root());
    cout << "Number of nodes in the Binary Tree: " << nodes << endl;

    cout << "Pre-Order Traversal: "; 
    b1->pre_order(b1->get_root());
    cout << endl;
    
    cout << "In-Order Traversal: ";
    b1->in_order(b1->get_root());
    cout << endl;

    cout << "Post-Order Traversal: ";
    b1->post_order(b1->get_root());
    cout << endl;

    cout << "Level Order BFS Tree Traversal: ";
    b1->LevelOrder();
    cout << endl;

/////////////////DELETE TREE TESTING////////////////////
    b1->delete_node(n5->value);
    cout << "Delete Node n5 (32): ";
    b1->post_order(b1->get_root());
    cout << endl;

    b1->delete_tree();
    cout << "Delete Tree: ";
    b1->post_order(b1->get_root());
    cout << endl;

////////////////////////HEAP SORT//////////////////////////////
//Sort this in an array
//If node is at index i
//left child is at 2i
//right child is at 2i+1
//parent is at 0.5i
//Best case: O(1)
//Worst case: O(logn)

int array[6] = {12,11,13,5,6,7}; //unsorted array
int size = 6; //6 elements
BinaryTrees* b2 = new BinaryTrees(array,size);

cout << "Sorted Array using HeapSort: ";
b2->HeapSort();
b2->print_array();

}
 