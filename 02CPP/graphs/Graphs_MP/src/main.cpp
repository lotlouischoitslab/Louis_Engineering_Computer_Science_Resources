#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "graphs.hpp"

using namespace std;

/*Graphs are very important!*/
/*Set of vertices V and edges E
G = {V,E}
Directed or UnDirected
Edge (u,v) u->v if ordered

*/

void test_graph1() {
    cout << "Test 1: Testing for Adjacency Matrix: " << endl;
    const int v1 = 5;
    int** graph = new int*[v1];
    for(int i = 0; i < v1; i++) {
        graph[i] = new int[v1];
    }

    for(int i = 0; i < v1; i++) {
        for(int j = 0; j < v1; j++) {
            graph[i][j] = 0;
        }
    }

    Graphs* g1 = new Graphs(graph,v1,v1);
    g1->addEdge_initial(0, 1);
    g1->addEdge_initial(0, 4);
    g1->addEdge_initial(1, 1);
    g1->addEdge_initial(1, 2);
    g1->addEdge_initial(1, 3);
    g1->addEdge_initial(1, 4);
    g1->addEdge_initial(3, 2);
    g1->addEdge_initial(3, 4);
    g1->print_graph_matrix();
    cout << "End of Test Case\n" << endl;
}

void test_graph2() {
    cout << "Test 2: Testing for Unweighted Adjacency List: " << endl;
    const int v2 = 5;
    vector<int> graph[v2];
    Graphs* g2 = new Graphs(graph,v2);
    g2->addEdge_initial(0, 1);
    g2->addEdge_initial(0, 4);
    g2->addEdge_initial(1, 1);
    g2->addEdge_initial(1, 2);
    g2->addEdge_initial(1, 3);
    g2->addEdge_initial(1, 4);
    g2->addEdge_initial(3, 2);
    g2->addEdge_initial(3, 4);
    cout << "Adjacency List:" << endl;
    g2->print_graph_vector();
    cout << "\nEnd of Test Case\n" << endl;
}

void test_graph3() {
    const int v2 = 5;
    vector<pair<int,int>> graph[v2];
    cout << "Test 3: Testing for Weighted Adjacency List: " << endl;
    Graphs* g2 = new Graphs();
    g2->addEdge(graph, 0, 1, 1);
    g2->addEdge(graph, 0, 4, 5);
    g2->addEdge(graph, 1, 1, 2);
    g2->addEdge(graph, 1, 2, 3);
    g2->addEdge(graph, 1, 3, 4);
    g2->addEdge(graph, 1, 4, 2);
    g2->addEdge(graph, 3, 2, 2);
    g2->addEdge(graph, 3, 4, 3);

    cout << "Adjacency List:" << endl;
    for (size_t i=0; i < v2; i++)
    {
        cout << i;
        for (size_t j=0; j < graph[i].size(); j++)
            cout << " -> " << graph[i][j].first << "," << graph[i][j].second;
        cout << endl;
    }
    cout << "End of Test Case\n" << endl;
}

int main() {
    test_graph1();
    test_graph2();
    test_graph3();

    return 0;
}
