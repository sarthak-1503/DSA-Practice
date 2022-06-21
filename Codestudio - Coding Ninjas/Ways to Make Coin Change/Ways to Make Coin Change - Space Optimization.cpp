// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471

#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
     vector<long> dp(value+1,0);
    dp[0] = 1;
    vector<long> prev;
    
    for(int i=0;i<=n;i++)
    {
        dp = vector<long> (value+1,0);
        
        for(int j=0;j<=value;j++)
        {
            if(j == 0)
            {
                dp[j] = 1;
            }
            else if(i == 0)
            {
                dp[j] = 0;
            }
            else
            {
                dp[j] += prev[j];
                
                if(j >= denominations[i-1])
                {
                    dp[j] += dp[j-denominations[i-1]];
                }
            }
        }
        
        prev = dp;
    }
    
    return dp[value];
}