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