#include "graphSTL.h"

int main()
{
    int V = 5;
    vector<int> adj[V];
	addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    bfs(0, adj, V);
    return 0;
}
