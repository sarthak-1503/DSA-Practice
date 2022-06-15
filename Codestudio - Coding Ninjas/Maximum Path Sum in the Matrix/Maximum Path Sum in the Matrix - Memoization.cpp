// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<vector<int>> &matrix,int row,int col,int m,int n,vector<vector<int>> &dp)
{
    if(row < 0 || col < 0 || row >= m || col >= n)
    {
        return (long long)INT_MIN;
    }
    
    if(row == m-1)
    {
        return dp[row][col] = matrix[row][col];
    }
    
    if(dp[row][col] != -1)
    {
        return dp[row][col];
    }
    
    return dp[row][col] = matrix[row][col] + 
        max(maxSum(matrix,row+1,col,m,n,dp),max(maxSum(matrix,row+1,col-1,m,n,dp),maxSum(matrix,row+1,col+1,m,n,dp)));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    long long ma = INT_MIN;
    vector<vector<int>> dp(m,vector<int> (n,-1));
    
    for(int i=0;i<n;i++)
    {
//         vector<vector<int>> dp(m,vector<int> (n,-1));
        ma = max(ma,(long long)maxSum(matrix,0,i,m,n,dp));
    }
    
    return ma;
}