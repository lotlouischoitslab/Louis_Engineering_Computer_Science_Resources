#include <iostream>
#include <stdlib.h>

using namespace std;

#define V 5

/* Advantages:
Adding/Removing and Edge takes O(1) time
Whether there is an edge from u to v takes O(1) time
Disadvantages:
Consumes more time O(V^2) time even if the graph is sparse
Adding or removing vertex is O(V^2) time
*/
void addEdge(int** graph, int u, int v) {
    graph[u][v] = 1;
}

int main() {
    int** graph = new int* [V];
    for(int j = 0; j < V; j++) {
        graph[j] = new int[j];
    }

    for(int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
   
    /*Refer to the image I have in the file*/

    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,1);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,3,2);
    addEdge(graph,3,4);

    cout << "Adjacent Matrix: " << endl;

    for(size_t i = 0; i < V; i++) {
        for(size_t j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}