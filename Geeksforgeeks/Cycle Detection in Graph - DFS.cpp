// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> pi;

    bool DFS(int node, int parent, vector<bool> &visited, vector<int> adj[], int V)
    {
        visited[node] = true;

        for (auto u : adj[node])
        {
            if (!visited[u])
            {
                visited[u] = true;

                if (DFS(u, node, visited, adj, V))
                {
                    return true;
                }
            }
            else
            {
                if (u != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && DFS(i, -1, visited, adj, V))
            {
                return true;
            }
        }

        return false;
    }
};