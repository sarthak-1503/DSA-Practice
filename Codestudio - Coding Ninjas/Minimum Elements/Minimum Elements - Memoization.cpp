// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

#include<bits/stdc++.h>
using namespace std;

int minElementsForTargetSum(int n,int x,vector<int> &num,vector<vector<int>> &dp)
{
    if(n < 0 || x < 0)
    {
        return INT_MAX;
    }
    
    if(dp[n][x] != -1)
    {
        return dp[n][x];
    }
    
    if(x == 0)
    {
        return dp[n][x] = 0;
    }
    
    if(n == 0)
    {
        if(num[n] <= x && (x % num[n] == 0))
        {
            return dp[n][x] = x/num[n];
        }
        
        return dp[n][x] = INT_MAX;
    }
    
    int taken = INT_MAX, notTaken;
    notTaken = minElementsForTargetSum(n-1,x,num,dp);
    
    if(num[n] <= x)
    {
        int repeatingElement = minElementsForTargetSum(n,x-num[n],num,dp);
        int previousResult = minElementsForTargetSum(n-1,x-num[n],num,dp);
        
        if(repeatingElement == INT_MAX && previousResult == INT_MAX)
        {
            taken = INT_MAX;
        }
        else
        {
            taken = min(repeatingElement,previousResult) + 1;    
        }
    }
        
    return dp[n][x] = min(taken,notTaken);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n,vector<int> (x+1,-1));
    
    int result = minElementsForTargetSum(n-1,x,num,dp);
    
    if(result == INT_MAX)
    {
        result = -1;
    }
    
    return result;
}