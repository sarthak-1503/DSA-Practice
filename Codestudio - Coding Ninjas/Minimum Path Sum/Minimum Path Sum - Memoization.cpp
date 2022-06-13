// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

#include<bits/stdc++.h>
using namespace std;

int minSum(int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    if(m == 0 || n == 0)
    {
        return INT_MAX;
    }
    
    if(m == 1 && n == 1)
    {
        return dp[m][n] = grid[m-1][n-1];
    }
    
    if(dp[m][n] != INT_MAX)
    {
        return dp[m][n];
    }
    
    return dp[m][n] = min(minSum(m-1,n,grid,dp),minSum(m,n-1,grid,dp)) + grid[m-1][n-1];
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> dp(m+1,vector<int> (n+1,INT_MAX));
    
    return minSum(m,n,grid,dp);
}