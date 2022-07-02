// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // Write your code here
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    queue<int> q;
    vector<int> parent(n + 1, -1);
    vector<int> distance(n + 1, INT_MAX);
    q.push(s);
    distance[s] = 0;

    while (!q.empty())
    {
        int house = q.front();
        q.pop();

        for (auto connectedHouse : adj[house])
        {
            if (distance[house] + 1 < distance[connectedHouse])
            {
                distance[connectedHouse] = distance[house] + 1;
                q.push(connectedHouse);
                parent[connectedHouse] = house;
            }
        }
    }

    vector<int> ans;
    int start = t;

    while (start != s)
    {
        ans.push_back(start);
        start = parent[start];
    }

    ans.push_back(s);
    reverse(ans.begin(), ans.end());

    return ans;
}
