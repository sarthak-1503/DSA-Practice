// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include<bits/stdc++.h>
using namespace std;

int frogJumpDP(vector<int> &heights,vector<int> &dp, int index)
{
    if(index == 0)
    {
        return 0;
    }
    
    if(dp[index] != -1)
    {
        return dp[index];
    }
    
    int onestep = frogJumpDP(heights,dp,index-1) + abs(heights[index]-heights[index-1]);
    int twosteps = INT_MAX;
    
    if(index > 1)
    {
        twosteps = frogJumpDP(heights,dp,index-2) + abs(heights[index]-heights[index-2]);
    }
    
    dp[index] = min(onestep,twosteps);
    
    return dp[index];
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return frogJumpDP(heights,dp,n-1);
}