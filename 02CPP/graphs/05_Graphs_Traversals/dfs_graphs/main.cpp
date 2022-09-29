#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

#define V 7

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void dfs_iterative(vector<int> graph[], int start) {
    vector<bool> visited(graph->size(),false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while(!s.empty()) {
        int v = s.top();
        cout << v << " ";
        s.pop();
        //Enqueue all the adjacent nodes of v and mark them visited
        for (auto i = graph[v].begin(); i != graph[v].end(); i++) {
            if(!visited[*i]) {
                s.push(*i);
                visited[*i] = true;
            }
        }
    }
}

void dfs_recursive(vector<int> graph[], vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";
    for (auto i = graph[node].begin(); i != graph[node].end(); i++) {
        if(!visited[*i]) {
            dfs_recursive(graph, visited,*i);
        }
    }
}

int main() {
    vector<int> graph[V];
    /*Refer to the dfs graph image I have in the file*/

    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,2,6);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,5,6);

    cout << "DFS Iterative Traversal starting from Node 0: ";
    dfs_iterative(graph, 0);
    cout << endl;

    cout << "DFS Recursive Traversal starting from Node 0: ";
    vector<bool> visited(graph->size(), false);
    dfs_recursive(graph, visited, 0);
    cout << endl;
    
    return 0;
}