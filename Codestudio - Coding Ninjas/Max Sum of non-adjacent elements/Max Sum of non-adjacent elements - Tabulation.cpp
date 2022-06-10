// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    
    if(n > 1)
    {
        dp[1] = max(nums[1],nums[0]);
    }
    
    for(int i=2;i<n;i++)
    {
        dp[i] = max(dp[i],dp[i-2] + nums[i]);
        
        dp[i] = max(dp[i],dp[i-1]);
    }
    
    return dp[n-1];
}