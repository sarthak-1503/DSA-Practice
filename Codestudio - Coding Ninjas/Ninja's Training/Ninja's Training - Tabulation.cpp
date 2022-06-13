// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

#include<bits/stdc++.h>
using namespace std;

long solve(vector<vector<int>> &points,int index,int last,vector<vector<long>> &dp)
{
    long ma = 0;
    
    if(dp[index][last] != -1)
    {
        return dp[index][last];
    }
    
    if(index == 0)
    {
        for(int i=0;i<3;i++)
        {
            if(i != last)
            {
                ma = max(ma,(long)points[index][i]);
            }
        }
        
        return dp[index][last] = ma;
    }
    
    for(int i=0;i<3;i++)
    {
        if(i != last)
        {
            ma = max(ma,(long)points[index][i] + solve(points,index-1,i,dp));
        }
    }
    
    return dp[index][last] = ma;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<long>> dp(n,vector<long> (4,-1));
    
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][1],points[0][0]);
    dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(j != k)
                {
                    dp[i][j] = max(dp[i][j],points[i][k] + dp[i-1][k]);
                }
            }
        }
    }
    
    return dp[n-1][3];
    
    return solve(points,n-1,3,dp);
}