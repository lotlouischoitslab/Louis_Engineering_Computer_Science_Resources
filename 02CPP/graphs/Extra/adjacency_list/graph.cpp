#include "graph.h"


////Using Adjacency List which is not recommended
Graph::Graph(int V) {
    vertex_ = V;
    list_ = new list<int>[vertex_];
}

void Graph::addEdge(int x, int y){
    list_[x].push_back(y);
}

void Graph::print() {
    for (int i = 0; i < vertex_; i++) {
        cout << "Vertex " << i << "->";
        for (int x: list_[i]) {
            cout << x << ",";
        }
        cout << endl;
    }
}

void Graph::BFS(int s) {
    bool *visited = new bool[vertex_];
    for (int i = 0; i < vertex_; i++) {
        visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()) {
        s = q.front();
        q.pop();
        cout << "check adjacent vertices for vertex " << s << endl;
        for (auto i = list_[s].begin(); i != list_[s].end(); i++) {
            if(!visited[*i]) {
                cout << "Visit and enqueue " << *i << endl;
                visited[*i] = true;
                //push back to check the vertex vertices
                q.push(*i);
            }
        }
    }
}

void Graph::DFS(int s) {
    bool *visited = new bool[vertex_];
    for (int i = 0; i < vertex_; ++i) {
        visited[i] = false;
    }
    DFS_helper(s,visited);
}

void Graph::DFS_helper(int s,bool* visited) {
    cout << "Visiting Node " << s << endl;
    visited[s] = true;

    //Go through the adjacency list 
    for (auto i = list_[s].begin(); i != list_[s].end(); i++) {
        if(!visited[*i]) {
            cout << "Going to vertex " << *i << " from vertex " << s << endl;
            DFS_helper(*i,visited);
        }
    }
}