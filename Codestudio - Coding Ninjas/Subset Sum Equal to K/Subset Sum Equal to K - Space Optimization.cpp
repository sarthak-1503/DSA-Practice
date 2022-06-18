// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<int> dp(k+1,0);
    vector<int> prev;
    
    for(int i=0;i<=n;i++)
    {
        dp = vector<int> (k+1,0);
        
        for(int j=0;j<=k;j++)
        {   
            if(j == 0)
            {
                dp[j] = true;
            }
            else if(i == 0)
            {
                dp[j] = false;
            }
            else
            {
                dp[j] |= prev[j];  
                
                if(j >= arr[i-1])
                {
                    dp[j] |= prev[j-arr[i-1]];
                }
            }
        }
        
        prev = dp;
    }
    
    return dp[k];
}
