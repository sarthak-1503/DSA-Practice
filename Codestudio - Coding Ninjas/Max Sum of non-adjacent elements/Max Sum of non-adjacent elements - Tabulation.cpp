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
        dp[1] = nums[1];
    }
    
    for(int i=2;i<n;i++)
    {
        dp[i] = max(dp[i],dp[i-2] + nums[i]);
        
        if(i >= 3)
        {
            dp[i] = max(dp[i],dp[i-3] + nums[i]);
        }
    }
    
    int temp = INT_MIN;
    
    if(n > 1)
    {
        temp = dp[n-2];
    }
    
    return max(temp,dp[n-1]);
}