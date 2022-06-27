
// * @lc app=leetcode id=2285 lang=cpp
// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj(n,0);
        
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]]++;
            adj[roads[i][1]]++;
        }
        
        sort(adj.begin(),adj.end());
        long long ans = 0;
        
        for(int i=0;i<n;i++)
        {
            ans += (long long)(i+1)*(adj[i]);
        }
        
        return ans;
    }
};

// @lc code=end