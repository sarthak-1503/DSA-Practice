#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        
        if(n == 1)
        {
            return 0;
        }
        
        sort(stockPrices.begin(),stockPrices.end());

        long long currY, currX;
        long long y = stockPrices[1][1] - stockPrices[0][1];
        long long x = stockPrices[1][0] - stockPrices[0][0];
        
        long ans = 1;
        
        for(int i=1;i<n-1;i++)
        {
            currY = stockPrices[i+1][1] - stockPrices[i][1];
            currX = stockPrices[i+1][0] - stockPrices[i][0];
            
            if(currX*y != currY*x)
            {
                ans++;
            }
            
            y = currY;
            x = currX;
        }
        
        return ans;
    }
};