// https://www.codingninjas.com/codestudio/problems/topological-sort_982938

#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<bool> &visited, vector<int> &ans, vector<vector<int>> &adj, int v)
{
    visited[node] = true;

    for (auto u : adj[node])
    {
        if (!visited[u])
        {
            visited[u] = true;
            DFS(u, visited, ans, adj, v);
        }
    }

    ans.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<vector<int>> adj(v, vector<int>());

    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(v, false);
    vector<int> ans;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFS(i, visited, ans, adj, v);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}