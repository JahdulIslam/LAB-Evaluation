#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    visited[s] = true;
    cout << s << " ";

    for (int neighbor : adj[s])
    {
        if (!visited[neighbor])
        {
            dfs(adj, visited, neighbor);
        }
    }
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    vector<bool> visited(V, false);
    dfs(adj, visited, 0);
    return 0;
}