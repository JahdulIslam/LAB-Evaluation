#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &adj, int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void displayList(vector<vector<int>> &adj)
{
    printf("Adjacency List:\n");
    for (int i = 0; i <adj.size(); i++)
    {
        printf("%d:", i);
        for (int j : adj[i])
        {
            printf(" %d", j);
        }
        printf("\n");
    }
}

int main()
{
    int V = 4;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    displayList(adj);
    return 0;
}