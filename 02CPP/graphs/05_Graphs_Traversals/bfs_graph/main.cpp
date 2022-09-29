#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

#define V 7

void addEdge(vector<int> *graph, int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void bfs(vector<int> *graph, int start) {
    vector<bool> visited(graph->size(),false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();
        //Enqueue all the adjacent nodes of v and mark them visited
        for (auto i = graph[v].begin(); i != graph[v].end(); i++) {
            if(!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}

int main() {
    vector<int> grid[V];
    vector<int> *graph = grid;
    /*Refer to the bfs graph image I have in the file*/

    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,2,6);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,5,6);

    cout << "BFS Traversal starting from Node 0: ";

    bfs(graph, 0);
    
    return 0;
}