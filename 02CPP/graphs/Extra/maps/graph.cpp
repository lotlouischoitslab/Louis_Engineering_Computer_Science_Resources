#include "graph.h"

void Graph::addEdge(string x, string y, bool bidir, int weight){
    list_[x].push_back(make_pair(y,weight));
    if(bidir) {
        list_[y].push_back(make_pair(x,weight));
    }
}

void Graph::BFS(string x) {
    
}

void Graph::print(){
    //iterate over all edges
    for (auto p:list_) {
        string smart_city = p.first;
        list<pair<string,int>> neighbors = p.second;
        for (auto neigh : neighbors) {
            string dest = neigh.first;
            int dist = neigh.second;
            cout << dest << " " << dist << ",";
        }
        cout << endl;
    }
}