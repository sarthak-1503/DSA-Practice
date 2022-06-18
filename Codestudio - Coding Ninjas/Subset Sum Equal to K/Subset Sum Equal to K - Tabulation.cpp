// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j] = false;
            
            if(j == 0)
            {
                dp[i][j] = true;
            }
            else if(i == 0)
            {
                dp[i][j] = false;
            }
            else
            {
                dp[i][j] |= dp[i-1][j];  
                
                if(j >= arr[i-1])
                {
                    dp[i][j] |= dp[i-1][j-arr[i-1]];
                }
            }
        }
    }
    
    return dp[n][k];
}
