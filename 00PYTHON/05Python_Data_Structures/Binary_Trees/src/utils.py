class BinarySearchTree:
    def __init__(self,data=None):
        self.data = data 
        self.left = None 
        self.right = None 

    #Build Binary-Search-Tree
    def build_tree(self,elements):
        root = BinarySearchTree(elements[0])
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

    #Height of BST
    def height(self,root):
        if root is None:
            return -1
        left = self.height(root.left) 
        right = self.height(root.right)
        return 1+max(left,right)

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
            return self.data
        left = self.left.total() if self.left else 0
        right = self.right.total() if self.right else 0
        return self.data + left + right
        
    #Breadth-First-Search Algorithms for Trees

    #Level Order Traversal
    def level_order_bfs(self):
        if self is None:
            return []
        queue = [self]
        results = [self.data]

        while len(queue) != 0:
            s = queue.pop(0)
            if s.left:
                queue.append(s.left)
                results.append(s.left.data)
            if s.right:
                queue.append(s.right)
                results.append(s.right.data)

        return results


    #Depth-First-Search Algorithms for Trees
    #Pre-Order Traversal DFS
    def pre_order_dfs(self):
        results = [self.data]
        if self.left:
            results += self.left.pre_order_dfs()
        if self.right:
            results += self.right.pre_order_dfs()
        return results 

    #In-Order Traversal DFS
    def in_order_dfs(self):
        results = []

        if self.left:
            results += self.left.in_order_dfs()

        results += [self.data]

        if self.right:
            results += self.right.in_order_dfs()
        return results

    #Post-Order DFS Traversal
    def post_order_dfs(self):
        results = []
        if self.left:
            results += self.left.post_order_dfs()
        
        if self.right:
            results += self.right.post_order_dfs()
        
        results+=[self.data]
        return results
