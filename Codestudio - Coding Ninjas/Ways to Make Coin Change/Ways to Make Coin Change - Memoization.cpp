// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471

#include<bits/stdc++.h>
using namespace std;

long noOfWays(int n,int value,int *denominations,vector<vector<long>> &dp)
{
    if(n < 0 || value < 0)   
     {
         return 0;
     }
    
    if(dp[n][value] != -1)
    {
        return dp[n][value];
    }
    
    if(value == 0)
    {
        return 1;
    }
    
    if(n == 0)
    {
        return 0;
    }
    
    long taken = 0, notTaken;
    
    notTaken = noOfWays(n-1,value,denominations,dp);
    
    if(value >= denominations[n-1])
    {
        taken = noOfWays(n,value-denominations[n-1],denominations,dp);
    }
    
    return dp[n][value] = taken + notTaken;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
     vector<vector<long>> dp(n+1,vector<long> (value+1,-1));
    
    return noOfWays(n,value,denominations,dp);
}