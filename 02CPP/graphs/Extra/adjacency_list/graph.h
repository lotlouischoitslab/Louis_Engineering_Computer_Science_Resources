#include <iostream>
#include <list>
#include <queue>
using namespace std;

#pragma once

class Graph {
    public:
        Graph(int V);
        void addEdge(int x, int y);
        void print();
        void BFS(int s);
        void DFS(int s);
        void DFS_helper(int s, bool* visited);

    private:
        int vertex_;
        list<int> *list_; //new list


};