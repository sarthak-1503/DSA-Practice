// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885

#include<bits/stdc++.h>
using namespace std;

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    
    if(r == 1)
    {
        if(c == 1)
        {
            return grid[0][0];
        }
        
        return grid[0][0] + grid[0][c-1];
    }

    vector<vector<int>> dp;
    vector<vector<int>> prev;
    
    for(int i=r-1;i>=0;i--)
    {
        dp = vector<vector<int>> (c,vector<int> (c,-1));
        
        for(int j1=0;j1<c;j1++)
        {
            for(int j2=0;j2<c;j2++)
            {
                for(int z=-1;z<=1;z++)
                {
                    for(int k=-1;k<=1;k++)
                    {
                        if(i == r - 1)
                        {
                            if(j1 == j2)
                            {
                                dp[j1][j2] = grid[i][j1];
                            }
                            else
                            {
                                dp[j1][j2] = grid[i][j1] + grid[i][j2];
                            }
                        }
                        else
                        {
                            if(j1+z < c && j2+k < c && j1+z >= 0 && j2+k >= 0)
                            {
                                 if(j1 == j2)
                                {
                                    dp[j1][j2] = max(dp[j1][j2],grid[i][j1] + prev[j1+z][j2+k]);   
                                }
                                else
                                {
                                    dp[j1][j2] = max(dp[j1][j2],grid[i][j1] + grid[i][j2] + prev[j1+z][j2+k]);
                                }   
                            }
                        }
                        
                    }
                }
            }
        }
        
        prev = dp;
    }
    return dp[0][c-1];
}

int collectMax(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
{
    if(i < 0 || i >= r || j1 < 0 || j1 >= c || j2 < 0 | j2 >= c)
    {
        return -1e8;
    }
    
    if(dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    
    if(i == r - 1)
    {
        if(j1 == j2)
        {
            return dp[i][j1][j2] = grid[i][j1];
        }
        
        return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
    }
    
    int ma = 0;
    
    for(int z=-1;z<=1;z++)
    {
        for(int k=-1;k<=1;k++)
        {
            if(j1 == j2)
            {
                ma = max(ma,grid[i][j1] + collectMax(i+1,j1+z,j2+k,r,c,grid,dp));
            }
            else
            {
                ma = max(ma,grid[i][j1] + grid[i][j2] + collectMax(i+1,j1+z,j2+k,r,c,grid,dp));
            }
        }
    }
    
    return dp[i][j1][j2] = ma;
    
}