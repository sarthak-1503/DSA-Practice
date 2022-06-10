// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int index,vector<int> &dp)
{
    if(index == 0)
    {
        return nums[index];
    }
    
    if(index < 0)
    {
        return 0;
    }
    
    if(dp[index] != -1)
    {
        return dp[index];
    }
    
    int last = solve(nums,index-2,dp) + nums[index];
    int secondlast = solve(nums,index-1,dp);
    
    return dp[index] = max(last,secondlast);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n+1,-1);
    
    return solve(nums,n-1,dp);
}