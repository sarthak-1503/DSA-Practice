/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans;
        vector<int> store;

        for(int i=0;i<n;i++)
        {
            if(s[i] == c)
            {
                store.push_back(i);
            }
        }

        for(int i=0;i<n;i++)
        {
            int index = lower_bound(store.begin(),store.end(),i) - store.begin();

            if(index < store.size())
            {
                if(index)
                {
                    ans.push_back(min(i-store[index-1],store[index]-i));
                }
                else
                {
                    ans.push_back(store[index]-i);
                }
            }
            else
            {
                ans.push_back(i-store[index-1]);
            }
        }

        return ans;
    }
};
// @lc code=end

