// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // Write your code here
    vector<vector<int>> dp(n+1,vector<int> (maxWeight+1,-1));
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                
                if(weight[i-1] <= j)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-weight[i-1]] + value[i-1]);
                }
            }
        }
    }
    
    return dp[n][maxWeight];
}


