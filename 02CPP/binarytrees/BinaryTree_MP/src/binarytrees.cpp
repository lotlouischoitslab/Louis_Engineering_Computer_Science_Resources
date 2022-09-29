#include "binarytrees.hpp"

BinaryTrees::BinaryTrees() : root_(nullptr) {}

BinaryTrees::BinaryTrees(Node* rootNode) : root_(rootNode) {};

BinaryTrees::BinaryTrees(int* array, int size) : array_(array), size_of_array_(size){};

int BinaryTrees::Height(Node* root) { 
    if(!root) {
        return -1;
    } 
    return 1 + max(Height(root->left),Height(root->right));
}

int BinaryTrees::maxDepth(Node* node) 
{ 
    if (node == NULL) 
        return -1;
    else
    { 
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left); 
        int rDepth = maxDepth(node->right); 
    
        /* use the larger one */
        if (lDepth > rDepth) 
            return(lDepth + 1); 
        else return(rDepth + 1); 
    } 
} 

int BinaryTrees::minDepth(Node *root)
{
    // Corner case. Should never be hit unless the code is 
    // called on root = NULL
    if (root == NULL)
        return 0;

    // Base case : Leaf Node. This accounts for height = 1.
    if (root->left == NULL && root->right == NULL)
    return 1;
  
    int left = INT_MAX, right = INT_MAX;
    // If left subtree is not NULL, recur for left subtree
  
    if (root->left)
    left = minDepth(root->left);

    // If right subtree is not NULL, recur for right subtree
    if (root->right)
    right =  minDepth(root->right);

  //height will be minimum of left and right height +1 
    return 1 + min(left , right);
}

void BinaryTrees::insert(int value) {
    root_ = insert_helper(root_,value);
}

Node* BinaryTrees::insert_helper(Node* root, int value) {
    if(!root) return new Node(value);

    if(value <= root->value) {
        root->left = insert_helper(root->left,value);
    } else {
        root->right = insert_helper(root->right,value);
    }
    return root;
}

void BinaryTrees::pre_order(Node* current) {
    if(current) {
        cout << current->value << " ";
        pre_order(current->left);
        pre_order(current->right);
    }
}

void BinaryTrees::in_order(Node* current) {
    if(current) {
        in_order(current->left);
        cout << current->value << " ";
        in_order(current->right);
    }
}

void BinaryTrees::post_order(Node* current) {
    if(current) {
        post_order(current->left);
        post_order(current->right);
        cout << current->value << " ";
    }
}

Node* BinaryTrees::FindMin() { //left subtree
    return FindMin_helper(root_);
}

Node* BinaryTrees::FindMax() { //right subtree
    return FindMax_helper(root_);
}

Node* BinaryTrees::FindMin_helper(Node* current) { //left subtree helper function
    //Keep going left to find the minimum value of the tree
    while(current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* BinaryTrees::FindMax_helper(Node* current) { //right subtree helper function 
    //Keep going right to find the maximum value of the tree
    while(current->right != nullptr) {
        current = current->right;
    }
    return current;
}

void BinaryTrees::delete_tree() {
    delete_tree_helper(root_);
}

void BinaryTrees::delete_tree_helper(Node* &node) { //reference to a pointer
    if(!node) return;
    /*first delete both subtrees*/
    delete_tree_helper(node->left);
    delete_tree_helper(node->right);

    delete node;
    node = nullptr;
}

void BinaryTrees::delete_node(int value) {
    delete_node_helper(root_,value);
}

Node* BinaryTrees::delete_node_helper(Node* root, int value) {
   if(!root) return root; 
	else if(value < root->value) root->left = delete_node_helper(root->left,value);
	else if (value > root->value) root->right = delete_node_helper(root->right,value);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			Node *temp = FindMin_helper(root->right);
			root->value = temp->value;
			root->right = delete_node_helper(root->right,temp->value);
		}
	}
	return root;
}

/*BFS in Binary Trees*/
void BinaryTrees::LevelOrder() {
    LevelOrder_helper(root_);
    cout << endl;
    Display(root_);
}

void BinaryTrees::LevelOrder_helper(Node* &root) {
    if(!root) return;
    queue<Node*> Q;
    Q.push(root); 
    while(!Q.empty()) {
        Node* current = Q.front(); //front of the queue
        cout << current->value << " ";
        if(current->left) Q.push(current->left); //check if not null
        if(current->right) Q.push(current->right); //check if not null
        Q.pop(); //removing element at front
    }
}

void BinaryTrees::Display(Node* root) {
    // Base Case 
    if (root == NULL) return; 

    // Create an empty queue for level order traversal 
    queue<Node*> q; 

    // Enqueue Root and initialize height 
    q.push(root); 

    while (q.empty() == false) 
    { 
        // nodeCount (queue size) indicates number
        // of nodes at current level. 
        int nodeCount = q.size(); 

        // Dequeue all nodes of current level and 
        // Enqueue all nodes of next level 
        while (nodeCount > 0)
        { 
            Node* node = q.front(); 
            cout << node->value << " "; 
            q.pop(); 
            if (node->left != NULL) 
                q.push(node->left); 
            if (node->right != NULL) 
                q.push(node->right); 
            nodeCount--; 
        } 
        cout << endl; 
    } 
}

bool BinaryTrees::IsSubtreeLesser(Node* root, int value) {
    if(root == nullptr) return true; //Base Case
    if(root->value <= value 
    && IsSubtreeLesser(root->left,value) 
    && IsSubtreeLesser(root->right,value)) {
        return true;
    } else {
        return false;
    }
}

bool BinaryTrees::IsSubtreeGreater(Node* root, int value) {
    if(root == nullptr) return true; //Base Case
    if(root->value > value 
    && IsSubtreeGreater(root->left,value) 
    && IsSubtreeGreater(root->right,value)) {
        return true;
    } else {
        return false;
    }
}

bool BinaryTrees::IsBinarySearchTree(Node* root) {
    if(root == nullptr) return true; //Base Case
    if(IsSubtreeLesser(root->left, root->value) && IsSubtreeGreater(root->right, root->value) 
    && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right)) {
        return true;
    } else {
        return false;
    }
}

bool BinaryTrees::IsBinarySearchTree(Node* root, int minValue, int maxValue) {
    if(root == nullptr) return true; //Base Case
    if(root->value > minValue && root->value < maxValue
    && IsBinarySearchTree(root->left, minValue, root->value) 
    && IsBinarySearchTree(root->right, root->value, maxValue)) {
        return true;
    } else {
        return false;
    }
}


int BinaryTrees::count_nodes(Node* root) {
    if(!root) return 0; //if the tree is empty
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void BinaryTrees::Heapify(int* arr, int size, int i) {
    int largest = i; //initialize largest as root
    int left = 2*i + 1; //left child
    int right = 2*i+2; //right child
    //if left child is greater than right child
    if(arr[left] > arr[largest] && left < size) {
        largest = left;
    }
    //if right child is greater than root
    if(arr[right] > arr[largest] && right < size) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[i],arr[largest]);
        //Recursively call the heapify function
        Heapify(arr,size,largest);
    }
    
}

void BinaryTrees::HeapSort() {
    for(int i = size_of_array_/2 - 1; i >= 0; i--) {
        Heapify(array_,size_of_array_,i);
    }
    //One by one extraction of elements from heap
    for(int i = size_of_array_-1; i > 0; i--) {
        swap(array_[0],array_[i]);
        Heapify(array_,i,0);
    }
}

void BinaryTrees::print_array() {
  for (int i = 0; i < 6; i++) {
    cout << array_[i] << " ";
   }
}