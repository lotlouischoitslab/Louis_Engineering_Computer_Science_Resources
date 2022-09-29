#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    //bidirectional graph
    Graph g(6);
    //Vertex 0
    g.addEdge(0,1);
    g.addEdge(0,2);

    //vertex 1
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(1,4);

    //vertex 2
    g.addEdge(2,0);
    g.addEdge(2,4);

    //vertex 3
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(3,5);

    //vertex 4
    g.addEdge(4,1);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.addEdge(4,5);

    //vertex 5
    g.addEdge(5,3);
    g.addEdge(5,4);

    cout << "\nBFS Traversal " << endl;
    //BFS
    int bfs_starting_point = 4;
    g.BFS(bfs_starting_point); //starting point 

    cout << "\nDFS Traversal " << endl;
    //DFS
    int dfs_starting_point = 0;
    g.DFS(dfs_starting_point); //starting point 

    cout << endl;
    cout << "Graph " << endl;
    g.print();
    return 0;
}