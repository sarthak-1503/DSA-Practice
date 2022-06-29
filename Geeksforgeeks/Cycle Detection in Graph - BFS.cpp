// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> pi;

    bool BFS(int node, vector<bool> &visited, vector<int> adj[], int V)
    {
        queue<pi> q;
        q.push({node, -1});
        visited[node] = true;

        while (!q.empty())
        {
            int currnode = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto u : adj[currnode])
            {
                if (!visited[u])
                {
                    q.push({u, currnode});
                    visited[u] = true;
                }
                else if (u != parent)
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
            if (!visited[i] && BFS(i, visited, adj, V))
            {
                return true;
            }
        }

        return false;
    }
};