// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

#include <bits/stdc++.h> 
using namespace std;

int totalPaths(int m,int n,vector<vector<int>> &dp)
{
    if(m == 0 || n == 0)
    {
        return dp[m][n] = 0;
    }
    
    if(m == 1 || n == 1)
    {
        return dp[m][n] = 1;
    }
    
    if(dp[m][n] != -1)
    {
        return dp[m][n];
    }
    
    return dp[m][n] = totalPaths(m-1,n,dp) + totalPaths(m,n-1,dp);
}

int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    
    return totalPaths(m,n,dp);
}