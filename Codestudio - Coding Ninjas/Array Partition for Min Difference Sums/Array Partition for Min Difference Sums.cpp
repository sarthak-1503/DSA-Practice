// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int n, int k, vector<int> &arr,vector<vector<int>> &dp) {
    // Write your code here.
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

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    long long sum = accumulate(arr.begin(),arr.end(),0);
    
    vector<vector<int>> dp(n+1,vector<int> (sum/2+1,-1));
    
    subsetSum(n,sum/2,arr,dp);
    int mi = INT_MAX;
    
    for(int i=sum/2;i>=0;i--)
    {
        if(dp[n][i] == 1)
        {
            mi = min(mi, (int)abs(2*i-sum));
        }
    }
    
    return mi;
}
