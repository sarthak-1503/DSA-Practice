// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<ll>> dp(n,vector<ll> (m,0));
    ll mod = 1e9 + 7;
    
    for(int i=0;i<n;i++)
    {
        if(mat[i][0] != -1)
        {
            dp[i][0] = 1;
        }
        else
        {
            break;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        if(mat[0][i] != -1)
        {
            dp[0][i] = 1;
        }
        else
        {
            break;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j] != -1)
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }
    
    return (dp[n-1][m-1]) % mod;
}