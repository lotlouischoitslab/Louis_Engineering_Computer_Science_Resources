#include <iostream>
#include <list>
#include <cstring>
#include <unordered_map>
using namespace std;

#pragma once

class Graph {
    public:
        void addEdge(string x, string y, bool bidir, int weight);
        void BFS(string x);
        void print();
    private:
        unordered_map<string,list<pair<string,int>>>list_;


};