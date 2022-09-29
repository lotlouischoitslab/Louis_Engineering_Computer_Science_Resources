#include "graphs.hpp"

Graphs::Graphs(int** graphs, int rows, int cols) : graph_(graphs), rows_(rows), cols_(cols) {};

Graphs::Graphs(vector<int> *vect, int size) : list_(vect), size_of_vector_(size) {};

void Graphs::addEdge_initial(int u, int v) {
    graph_[u][v] = 1;
}

void Graphs::addEdge(int u, int v) {
    list_[u].emplace_back(v);
    //list_[v].emplace_back(u);
}

void Graphs::addEdge(vector<pair<int,int>> *graph, int u, int v, int weight){
    graph[u].emplace_back(make_pair(v, weight));
}

void Graphs::print_graph_matrix() {
    for(int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            cout << graph_[i][j] << " ";
        }
        cout << endl;
    }
}

void Graphs::print_graph_vector() {
    cout << list_->size();
    for (int i=0; i < size_of_vector_; i++){
        cout << i;
        for (int j=0; j < size_of_vector_; j++)
            cout << " -> " << (list_[i][j]) << "," ;
        cout << endl;
    }
}

/////Breadth First Search uses Queue First in First out

void Graphs::bfs(int start) {
    vector<bool> visited(list_->size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        cout << v << "  ";
        q.pop();
        // Enqueue all adjacent nodes of v and mark them visited
        for (auto i = list_[v].begin(); i != list_[v].end(); i++) {
            if (!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}