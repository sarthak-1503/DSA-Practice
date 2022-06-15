// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include<bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int> (n,-1));
    
    dp[m-1] = matrix[m-1];
    
    for(int i=m-2;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j] = matrix[i][j]+dp[i+1][j];
            
            if(j > 0)
            {
                dp[i][j] = max(dp[i][j],matrix[i][j] + dp[i+1][j-1]);
            }
            
            if(j < n-1)
            {
                dp[i][j] = max(dp[i][j],matrix[i][j] + dp[i+1][j+1]);
            }
        }
    }
    
    return *max_element(dp[0].begin(),dp[0].end());
}