
// @lc app=leetcode id=2316 lang=cpp

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(int node, vector<bool> &visited, vector<vector<int>> &adj, long long &cnt)
    {
        visited[node] = true;

        for (auto v : adj[node])
        {
            if (!visited[v])
            {
                visited[v] = true;
                cnt++;
                DFS(v, visited, adj, cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n, vector<int>());

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        vector<long long> store;
        long long cnt;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cnt = 1;
                DFS(i, visited, adj, cnt);
                store.push_back(cnt);
            }
        }

        for (int i = 1; i < store.size(); i++)
        {
            store[i] += store[i - 1];
        }

        long long ans = 0;

        for (int i = 0; i < store.size(); i++)
        {
            if (i == 0)
            {
                ans += (store[i]) * (store.back() - store[i]);
            }
            else
            {
                ans += (store[i] - store[i - 1]) * (store.back() - store[i]);
            }
        }

        return ans;
    }
};

// @lc code=end