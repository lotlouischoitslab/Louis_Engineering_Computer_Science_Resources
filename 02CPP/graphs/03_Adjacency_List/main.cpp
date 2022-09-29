#include <iostream>
#include <stdlib.h>

using namespace std;
#include <vector>

#define V 5

/* Adjacency List is collection of unordered lists to represent finite graph
 * The order does NOT matter for the list set for the graph!
 * For directed graphs, check for the outgoing nodes only.
 * Advantages:
 * Space O(V+E)
 * Adding an edge or a vertex takes O(1) time
 * Disadvantages:
 * Whether there is an edge or not from vertex u to v done ine O(V)
 * Time taken to remove an edge takes O(E) time
 * Time taken to remove a vertex takes O(V+E) time
 */

void addEdge(vector<int>* graph, int u, int v) {
    graph[u].emplace_back(v);
}

void addEdgeweight(vector<pair<int,int>>* graph, int u, int v, int weight) {
    graph[u].emplace_back(make_pair(v,weight));
}

int main() {
    vector<int> grid[V];
    vector<int>* graph = grid;
    /*Refer to graph example 2 jpg*/
    cout << "Directed Unweighted Graph Adjacent List: " << endl;
    //outbound edges from a node
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,1);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,3,2);
    addEdge(graph,3,4);

    for(size_t i = 0; i < V; i++) {
        cout << i;
        for(size_t j = 0; j < graph[i].size(); j++) {
            cout << " -> " << graph[i][j];
        }
        cout << endl;
    }

    /*Refer to graph example 3 jpg*/
    cout << "\nDirected Weighted Graph Adjacent List: " << endl; 

    vector<pair<int,int>> gridw[V];
    vector<pair<int,int>> *graphw = gridw;
    addEdgeweight(graphw,0,1,1);
    addEdgeweight(graphw,0,4,5);
    addEdgeweight(graphw,1,1,2);
    addEdgeweight(graphw,1,2,3);
    addEdgeweight(graphw,1,3,4);
    addEdgeweight(graphw,1,4,2);
    addEdgeweight(graphw,3,2,2);
    addEdgeweight(graphw,3,4,3);

    for(size_t i = 0; i < V; i++) {
        cout << i;
        for(size_t j = 0; j < graphw[i].size(); j++) {
            cout << " -> " << graphw[i][j].first << "," << graphw[i][j].second;
        }
        cout << endl;
    }
    
    return 0;
}