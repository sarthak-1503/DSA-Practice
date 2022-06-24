// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    typedef pair<int,int> pi;
    
    public:
    
    static bool compare(pi &a,pi &b)
    {
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        
        return a.second < b.second;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pi> store(n);
        
        for(int i=0;i<n;i++)
        {
            store[i] = {start[i],end[i]};
        }
        
        sort(store.begin(),store.end(),compare);
        int i, j = 0;    
        int ans = 1;
        
        for(i=1;i<n;i++)
        {
            if(store[j].second < store[i].first)
            {
                ans++;
                j = i;
            }
        }
        
        return ans;
    }
};