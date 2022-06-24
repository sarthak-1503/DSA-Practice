// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int minAmount = 0, maxAmount = 0;
        int cnt = N/(K+1);
        
        if(N % (K+1))
        {
            cnt++;
        }
        
        for(int i=0;i<cnt;i++)
        {
            minAmount += candies[i];
            maxAmount += candies[N-i-1];
        }
        
        return {minAmount,maxAmount};
    }
};