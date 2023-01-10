class BinarySearchTree:
    def __init__(self,data):
        self.data = data 
        self.left = None 
        self.right = None 

    #Build Binary-Search-Tree
    def build_tree(self,elements):
        root = self.BinarySearchTree(elements[0])
        for i in range(1,len(elements)):
            root.add_child(elements[i])
        return root

    #Add a child in BST
    def add_child(self,data):
        if data == self.data: #if the data values are the same
            return  #don't do anything
        
        if data < self.data: #if it's less than the data inside the BST
            if self.left: #Make sure to Null guard 
                self.left.add_child(data) #Traverse the left
            else:
                self.left = BinarySearchTree(data) #Add to left child
        
        else:
            if self.right: #if it's greater than the data inside the BST
                self.right.add_child(data) #Make sure to null guard
            else:
                self.right = BinarySearchTree(data) #Add to right child

    #Delete a child in BST 
    def delete_child(self,data):
        if self == None:
            return
        
        if data < self.data:
            if self.left:
                self.left = self.left.delete_child(data)
        

    #Search function in a BST
    def search(self,data):
        if self.data == data: #We found the data!
            return True
        
        if data < self.data: #if the given data is less than the input
            if self.left: #Null guard
                self.left.search(data) #Go to the left
            else:
                return False #return False
        
        if data > self.data: #if the given data is greater than the input
            if self.right: #Null guard
                self.right.search(data) #Go to the right
            else:
                return False #Otherwise return False

    #Mathematical Functions

    #Maximum
    def max_val(self):
        if self.right is None:
            return self.data 
        return self.right.max_val()
    
    #Minimum
    def min_val(self):
        if self.left is None:
            return self.data 
        return self.left.min_val()

    #Total Value 
    def total(self):
        if self == None:
            return self.val 
        return self.val + self.left.total().val + self.right.total().val
        
    #Breadth-First-Search Algorithms for Trees

    #Level Order Traversal



    #Depth-First-Search Algorithms for Trees