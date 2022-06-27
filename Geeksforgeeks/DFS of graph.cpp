// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void DFS(int node, vector<bool> &visited, vector<int> adj[], int V, vector<int> &ans)
    {
        ans.push_back(node);

        for (auto u : adj[node])
        {
            if (!visited[u])
            {
                visited[u] = true;

                DFS(u, visited, adj, V, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        visited[0] = true;

        DFS(0, visited, adj, V, ans);

        return ans;
    }
};