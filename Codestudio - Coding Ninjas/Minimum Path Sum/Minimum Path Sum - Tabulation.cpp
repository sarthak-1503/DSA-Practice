// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

#include<bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dp(n,vector<int> (m,INT_MAX));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                if(i)
                {
                    dp[i][j] = min(dp[i][j],dp[i-1][j] + grid[i][j]);
                }
                
                if(j)
                {
                    dp[i][j] = min(dp[i][j],dp[i][j-1] + grid[i][j]);
                }
            }
        }
    }
    
    return dp[n-1][m-1];
    
}