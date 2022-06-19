// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int> &nums, int tar)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<long>> dp(n+1,vector<long> (tar+1,0));
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=tar;j++)
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
                dp[i][j] = dp[i-1][j];
                
                if(j >= nums[i-1])
                {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }
    }
    
    return dp[n][tar];
}