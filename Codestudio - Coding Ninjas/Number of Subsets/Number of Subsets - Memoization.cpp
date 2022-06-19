// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

#include<bits/stdc++.h>
using namespace std;

int noOfWays(int n,int tar,vector<int> &nums,vector<vector<long>>& dp)
{
    if(n < 0 || tar < 0)
    {
        return 0;
    }
    
    if(dp[n][tar] != -1)
    {
        return dp[n][tar];
    }
    
    if(tar == 0)
    {
        return dp[n][tar] = 1;
    }
    
    if(n == 0)
    {
        return dp[n][tar] = 0;
    }
    
    return dp[n][tar] = noOfWays(n-1,tar,nums,dp) + noOfWays(n-1,tar-nums[n-1],nums,dp);
}

int findWays(vector<int> &nums, int tar)
{
    // Write your code here.
    vector<vector<long>> dp(nums.size()+1,vector<long> (tar+1,-1));
    
    return noOfWays(nums.size(),tar,nums,dp);
}