// https://www.codingninjas.com/codestudio/problems/target-sum_4127362

#include<bits/stdc++.h>
using namespace std;

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int sum = accumulate(arr.begin(),arr.end(),0);
    vector<vector<int>> dp(n+1,vector<int> (sum/2+1,0));
    int countZero = 0;
    dp[0][0] = 1;
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum/2;j++)
        {
            if(j == 0)
            {
                if(i > 0 && arr[i-1] == 0)
                {
                    countZero++;
                }
                
                dp[i][j] = pow(2,countZero);
            }
            else
            {
                if(i > 0)
                {
                    dp[i][j] += dp[i-1][j];
                    
                    if(j >= arr[i-1])
                    {
                        dp[i][j] += dp[i-1][j-arr[i-1]];
                    }
                }
            }
        }
    }
    
    int ans = 0;
    
    for(int i=sum/2;i>=0;i--)
    {
        if(dp[n][i] && abs(2*i-sum) == abs(target))
        {
            ans += dp[n][i];
        }
    }
    
    return ans;
}
