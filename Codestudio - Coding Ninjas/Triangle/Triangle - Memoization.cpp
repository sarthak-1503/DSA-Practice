// https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include<bits/stdc++.h>
using namespace std;

int minSum(vector<vector<int>> &triangle,int i,int j,vector<vector<int>> &dp)
{
    if(i == triangle.size()-1)
    {
        return dp[i][j] = triangle[i][j];
    }
    
    if(i < triangle.size() && j < triangle[i].size() && dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    return dp[i][j] = triangle[i][j] +             min(minSum(triangle,i+1,j,dp),minSum(triangle,i+1,j+1,dp));
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n,vector<int> (n,-1));
    
    return minSum(triangle,0,0,dp);
}

