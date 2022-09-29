#include <iostream>
using namespace std;

#define V 5
#define E 8

/* Disadvantages:
It uses O(VE) space as opposed to O(V^2) for adjacnecy matrix
Whether note is related to other node is O(E)
Traversing a node's adjacent nodes is O(E)
*/
void addEdge(int** graph, int u, int v, int e)
{
    graph[u][e] = 1;
    if (u != v)
       graph[v][e] = -1;
}

int main()
{
    // 2d array of V*E
    int grid[V][E] = {0};
    int** graph = new int*[V];

    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            graph[i][j] = 0;
        }
    }

    // graph, start, end, edge
    addEdge(graph, 0, 1, 0);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 1, 5);
    addEdge(graph, 1, 2, 6);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 3, 2, 7);

    cout << "Incidence matrix:" << endl;
    for (int i=0; i < V; i++)
    {
        for (int j=0; j < E; j++)
            cout << graph[i][j] << "   ";
        cout << endl;
    }
    return 0;
}