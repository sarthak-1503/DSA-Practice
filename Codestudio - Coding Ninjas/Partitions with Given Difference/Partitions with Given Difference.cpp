// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

#include<bits/stdc++.h>
using namespace std;

int subsets(vector<int> &arr,int tar,vector<vector<long>> &dp)
{
    int n = arr.size();
    int countZero = 0;
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=tar;j++)
        {
            if(j == 0)
            {
                if(i > 0 && arr[i-1] == 0)
                {
                    countZero++;
                }
                
                dp[i][j] = pow(2,countZero);
            }
            else if(i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
                
                if(j >= arr[i-1])
                {
                    dp[i][j] += dp[i-1][j-arr[i-1]];
                }
            }
        }
    }
    
    return dp[n][tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = accumulate(arr.begin(),arr.end(),0);
    vector<vector<long>> dp(n+1,vector<long> (sum/2+1,0));
    
    subsets(arr,sum/2,dp);
    long long mod = 1e9 + 7;
    long long ans = 0;
    
    for(int i=sum/2;i>=0;i--)
    {
        if(dp[n][i] && abs(2*i-sum) == d)
        {
            ans = (ans + dp[n][i]) % mod;
        }
    }
    
    return ans;
}


