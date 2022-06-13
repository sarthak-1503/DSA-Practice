// https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
    // Write your code here
    vector<ll> dp;
    vector<ll> prev(n,1);
    ll mod = 1e9 + 7;
    
    for(int i=0;i<m;i++)
    {   
        dp = vector<ll> (n,0);
        
        if(i == 0)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] != -1)
                {
                    dp[j] = 1;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] != -1)
                {
                    if(j == 0)
                    {
                        if(i == 0 || (i > 0 && prev[j] == 1))
                        {
                            dp[j] = 1;
                        }
                    }
                    else
                    {
                        dp[j] = (prev[j] + dp[j-1]) % mod;
                    }
                }
            }
        }
        
        prev = dp;
    }
    
    return dp[n-1];
}