// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int n, int k, vector<int> &arr) {
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

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    long long sum = accumulate(arr.begin(),arr.end(),0);
    
    if(sum % 2)
    {
        return false;
    }
    
    return subsetSum(n,sum/2,arr);
}
