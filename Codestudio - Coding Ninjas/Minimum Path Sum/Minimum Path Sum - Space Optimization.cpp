// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

#include<bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();
    
    vector<int> dp;
    vector<int> prev;
    
    for(int i=0;i<m;i++)
    {
        dp = vector<int> (n,INT_MAX);
        
        if(i == 0)
        {
             for(int j=0;j<n;j++)
             {
                 if(j == 0)
                 {
                     dp[j] = grid[i][j];
                 }
                 else
                 {
                     dp[j] = dp[j-1] + grid[i][j];
                 }
             }
        }
        else
        {
             for(int j=0;j<n;j++)
             {
                 if(j == 0)
                 {
                     if(i == 0)
                     {
                         dp[j] = grid[i][j];
                     }
                     else
                     {
                         dp[j] = prev[j] + grid[i][j];
                     }
                 }
                 else
                 {
                     dp[j] = min(prev[j],dp[j-1]) + grid[i][j];
                 }
             }
        }
        
        prev = dp;
    }
    
    return dp[n-1];
}