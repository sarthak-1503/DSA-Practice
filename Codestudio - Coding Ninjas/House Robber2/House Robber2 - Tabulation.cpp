// https://www.codingninjas.com/codestudio/problems/house-robber_839733

#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<long long> dp(n,0);
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

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size() == 1)
    {
        return valueInHouse[0];
    }
    
    vector<int> temp, temp2;
    for(int i=0;i<valueInHouse.size();i++)
    {
        if(i != 0)
        {
            temp.push_back(valueInHouse[i]);
        }
        
        if(i != valueInHouse.size()-1)
        {
            temp2.push_back(valueInHouse[i]);
        }
    }
    
    int n = temp.size();
    
//     vector<long long> dp(n+1,-1);
    
    return max(solve(temp2),solve(temp));
}