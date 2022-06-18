// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980

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

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    long long sum = accumulate(arr.begin(),arr.end(),0);
    
    if(sum % 2)
    {
        return false;
    }
    
    vector<vector<int>> dp(n+1,vector<int> (sum/2+1,-1));
    
    return subsetSum(n,sum/2,arr,dp);
}
