#include <iostream>
#include <vector>
#include <list>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsUtil(int src, vector<int> adj[], vector<bool> &visited)
{
    visited[src] = true;
    cout << src << endl;
    for(int i =0; i < adj[src].size(); i++)
        if(visited[adj[src][i]] == false)
            dfsUtil(adj[src][i], adj, visited);
}

void dfs(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for(int i=0; i < V; i++)
        if(visited[i]==false)
            dfsUtil(i, adj, visited);
}

void bfs(int src, vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    list<int> queue;
    visited[src] = true;
    queue.push_back(src);
    while(!queue.empty())
    {
        src = queue.front();
        cout << src << endl;
        queue.pop_front();
        for(int i=0; i < adj[src].size(); i++)
        {
            if(visited[adj[src][i]] == false)
            {
                queue.push_back(adj[src][i]);
                visited[adj[src][i]] = true;
            }
        }
    }
}
