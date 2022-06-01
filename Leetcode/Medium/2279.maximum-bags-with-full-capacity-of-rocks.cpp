#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        
        vector<long long> store(n);
        
        for(int i=0;i<n;i++)
        {
            store[i] = (long long)(capacity[i] - rocks[i]);
        }
        
        sort(store.begin(),store.end());
        for(int i=1;i<n;i++)
        {
            store[i] += store[i-1];
        }
        
        int index = lower_bound(store.begin(),store.end(),additionalRocks) - store.begin();
        
        if(index != n && store[index] == additionalRocks)
        {
            index++;
        }
        
        return index;
    }
};