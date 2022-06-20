// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include<bits/stdc++.h>
using namespace std;

int maxValue(int n,int maxWt,vector<int> &weight,vector<int> &value,vector<vector<int>> &dp)
{
    
    if(n < 0)
    {
        return INT_MIN;
    }
   
    if(n == 0)
    {
        if(weight[n] <= maxWt)
        {
            return dp[n][maxWt] = value[n];
        }
        
        return dp[n][maxWt] = 0;
    }
    
    if(dp[n][maxWt] != -1)
    {
        return dp[n][maxWt];
    }
    
    int taken = INT_MIN, notTaken;
    notTaken = maxValue(n-1,maxWt,weight,value,dp);
    
    if(weight[n] <= maxWt)
    {
        taken = maxValue(n-1,maxWt-weight[n],weight,value,dp)+value[n];
    }
    
    return dp[n][maxWt] = max(taken,notTaken);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
    
    return maxValue(n-1,maxWeight,weight,value,dp);
}