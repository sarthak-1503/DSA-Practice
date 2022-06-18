// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int n, int k, vector<int> &arr) {
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
