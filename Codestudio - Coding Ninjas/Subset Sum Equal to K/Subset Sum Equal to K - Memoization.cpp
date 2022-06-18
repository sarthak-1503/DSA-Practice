// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int n,int k,vector<int> &arr,vector<vector<int>> &dp)
{
    if(n < 0 || k < 0)
    {
        return false;
    }
    
    if(k == 0)
    {
        return dp[n][k] = true;
    }
    
    if(n == 0)
    {
        return dp[n][k] = false;
    }
    
    if(dp[n][k] != -1)
    {
        return dp[n][k];
    }
    
    return dp[n][k] = subsetSum(n-1,k,arr,dp) || subsetSum(n-1,k-arr[n-1],arr,dp);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
    
    return subsetSum(n,k,arr,dp);
}