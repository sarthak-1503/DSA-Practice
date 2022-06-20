// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // Write your code here
    vector<int> dp;
    vector<int> prev;
    
    for(int i=0;i<=n;i++)
    {
        dp = vector<int> (maxWeight+1,0);
        
        for(int j=0;j<=maxWeight;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[j] = 0;
            }
            else
            {
                dp[j] = max(dp[j],prev[j]);
                
                if(weight[i-1] <= j)
                {
                    dp[j] = max(dp[j],prev[j-weight[i-1]] + value[i-1]);
                }
            }
        }
        
        prev = dp;
    }
    
    return dp[maxWeight];
}


