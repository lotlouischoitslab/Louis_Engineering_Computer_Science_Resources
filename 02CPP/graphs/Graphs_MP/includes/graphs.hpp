#ifndef GRAPHS_HPP
#define GRAPHS_HPP
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include<queue>
#include <stack>
using namespace std;

class Graphs{
    public:
        Graphs() = default;
        Graphs(int** graphs, int rows, int cols);
        Graphs(vector<int> *vect,int size);
        void addEdge_initial(int u, int v);
        void addEdge(int u, int v);
        void addEdge(vector<pair<int,int>> *graph, int u, int v, int weight);
        void bfs(int start);
        void print_graph_matrix();
        void print_graph_vector();
    private:
        int** graph_;
        vector<int> *list_;
        int rows_;
        int cols_;
        int size_of_vector_;
};

#endif 