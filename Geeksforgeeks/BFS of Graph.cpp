// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BFS(int node, vector<bool> &visited, vector<int> adj[], int V, vector<int> &ans)
    {
        queue<int> q;
        q.push(node);
        ans.push_back(node);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            for (auto u : adj[v])
            {
                if (!visited[u])
                {
                    visited[u] = true;
                    ans.push_back(u);
                    q.push(u);
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;

        BFS(0, visited, adj, V, ans);

        return ans;
    }
};