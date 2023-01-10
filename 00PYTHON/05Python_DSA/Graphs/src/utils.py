class Graph:
    def __init__(self,nodes):
        self.nodes = nodes #Nodes in the graph network
        self.graph = dict() #Because this is an empty dictionary, I will assume this to be empty dictionary

        #Now I will be adding empty edges!
        for n in self.nodes:
            self.graph[n] = []

    #Add edge to the graph network
    def addedge(self,u,v,weight):
        self.graph[u].append([v,weight])
    
    #Add a node/vertex to the graph network
    def addnode(self,node):
        if node not in self.nodes:
            self.nodes.append(node)
            if len(self.adj_list[node] == 0):
                del self.adj_list[node] 

    #Remove a node/vertex in the graph network
    def removedge(self,u,v,weight):
        if u in self.graph and v in self.graph:
            del self.graph[u]
            for i in self.graph:
                list1 = self.graph[i]
                for j in list1:
                    if node == j[0]:
                        list1.remove(j)
                        break
    
    #Degree of the node
    def degree(self,node):
        return len(self.graph[node])

    #Number of Edges
    def numedges(self):
        if self.directed:
            return (self.numvertices()*(self.numvertices()-1))/2
        return self.numvertices()*(self.numvertices()-1)
    
    #Number of Vertices
    def numvertices(self):
        return len(self.graph)

    #Print the entire Graph Network
    def print_graph(self):
        for node in self.nodes:
            print(node,'->',self.graph[node])
    
    #Fundamental Graph Algorithms from CS 374 Introduction to Algorithms & Models of Computation! 

    #Breadth-First-Search (BFS)
    def bfs(self,source):
        if len(self.graph) == 0: #check if the graph network is empty
            return [] #return an empty list if the graph is empty
        
        visited = [False for i in range(len(self.nodes))]
        visited[source] = True
        queue = [source] 
        traversed = []
        
        while len(queue) != 0:
            v = queue.pop(0)
            traversed.append(v)
            for i in self.graph:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
        return traversed

    #Depth-First-Search (DFS)
    def dfs(self,source):
        visited = set()
        return self.dfs_recursive(source,visited,[])

    #DFS Helper Function
    def dfs_recursive(self,source,visited,to_return):
        visited.add(source)
        to_return.append(source)

        for neighbor in self.graph[source]:
            if neighbor[0] not in visited:
                self.dfs_recursive(neighbor[0],visited,to_return)
        return to_return