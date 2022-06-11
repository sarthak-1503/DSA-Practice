// https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int> &nums,int index,vector<long long> &dp)
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
    
    long long last = solve(nums,index-2,dp) + nums[index];
    long long secondlast = solve(nums,index-1,dp);
    
    return dp[index] = max(last,secondlast);
}

long long houseRobber(vector<int>& valueInHouse)
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
    
    vector<long long> dp(n+1,-1), dp2(n+1,-1);
    
    
    return max(solve(temp2,n-1,dp2),solve(temp,n-1,dp));
}