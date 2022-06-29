// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462

#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<bool> &visited, vector<vector<int>> adj, int V, vector<int> &store)
{
    store.push_back(node);
    visited[node] = true;

    for (auto u : adj[node])
    {
        if (!visited[u])
        {
            visited[u] = true;
            DFS(u, visited, adj, V, store);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V, vector<int>());

    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(V, false);
    vector<vector<int>> ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> store;
            DFS(i, visited, adj, V, store);
            ans.push_back(store);
        }
    }

    return ans;
}