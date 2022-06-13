// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

#include <bits/stdc++.h> 
using namespace std;

int uniquePaths(int m, int n) {
	// Write your code here.
    vector<int> dp;
    vector<int> prev(n,1);
    
    for(int i=0;i<m;i++)
    {   
        dp = vector<int> (n,0);
        
        if(i == 0)
        {
            dp = prev;
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                if(j == 0)
                {
                    dp[0] = 1;
                }
                else
                {
                    dp[j] = prev[j] + dp[j-1];
                }
            }
        }
        
        prev = dp;
    }
    
    return dp[n-1];
}