// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471

#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
     vector<vector<long>> dp(n+1,vector<long> (value+1,0));
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=value;j++)
        {
            if(j == 0)
            {
                dp[i][j] = 1;
            }
            else if(i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] += dp[i-1][j];
                
                if(j >= denominations[i-1])
                {
                    dp[i][j] += dp[i][j-denominations[i-1]];
                }
            }
        }
    }
    
    return dp[n][value];
}