#include <iostream>
#include <vector>

using namespace std;

#define V 5
#define E 8

/* A list which stores for each vertex a list of objects representing edge incident to that vertex

*/

void addEdge(vector<pair<int,int>> *graph, int u, int v, int e)
{
    graph[u].emplace_back(make_pair(e,v));
}

int main()
{
    // array of vectors of pair of <edge,endvertex>
    vector<pair<int,int>> grid[V];

    vector<pair<int,int>> *graph = grid;
    
    // graph, start, end, edge
    addEdge(graph, 0, 1, 0);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 1, 5);
    addEdge(graph, 1, 2, 6);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 3, 2, 7);

    cout << "Incidence list:" << endl;
    for (int i=0; i < V; i++)
    {
        cout << i;
        for (int j=0; j < graph[i].size(); j++)
            cout << " --> " << graph[i][j].first << "," << graph[i][j].second;
        cout << endl;
    }
    return 0;
}