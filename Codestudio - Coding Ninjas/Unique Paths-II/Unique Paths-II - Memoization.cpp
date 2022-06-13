// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int totalPaths(int m,int n,vector<vector<ll>> &dp,vector<vector<int>> &mat,ll mod)
{
    if(m == 0 || n == 0)
    {
        return dp[m][n] = 0;
    }
    
    if(m == 1 || n == 1)
    {
        if(mat[m-1][n-1] == -1)
        {
            return dp[m][n] = 0;
        }
        
        return dp[m][n] = 1;
    }
    
    if(m > 0 && n > 0 && mat[m-1][n-1] == -1)
    {
        return dp[m][n] = 0;
    }
    
    if(dp[m][n] != -1)
    {
        return (dp[m][n] % mod);
    }
    
    return dp[m][n] = (totalPaths(m-1,n,dp,mat,mod) + totalPaths(m,n-1,dp,mat,mod)) % mod;
}

int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<ll>> dp(m+1,vector<ll> (n+1,-1));
    ll mod = 1e9 + 7;
    
    for(int i=1;i<=m;i++)
    {
        if(mat[i-1][0] == -1)
        {
            while(i <= m)
            {
                mat[i-1][0] = -1;
                i++;
            }
            
            break;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(mat[0][i-1] == -1)
        {
            while(i <= n)
            {
                mat[0][i-1] = -1;
                i++;
            }
            
            break;
        }
    }
    
    return totalPaths(m,n,dp,mat,mod);
}