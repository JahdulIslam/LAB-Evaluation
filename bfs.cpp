#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << " ";

        for (int neighbor : adj[f])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

    vector<bool> visited(V, false);
    bfs(adj, visited, 0);
    return 0;
}