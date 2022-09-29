#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    //bidirectional graph
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.print();
    

    return 0;
}