// https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include<bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n,vector<int> ());
    dp[n-1] = triangle[n-1];
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<i+1;j++)
        {
            dp[i].push_back(triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]));
        }
    }
    
    return dp[0][0];
}

