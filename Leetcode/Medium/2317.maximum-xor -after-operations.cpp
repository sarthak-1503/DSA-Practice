
// @lc app=leetcode id=2317 lang=cpp

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = nums.size();
        long ans = 0;
        
        for(int i=0;i<n;i++)
        {
            ans |= nums[i];
        }
        
        return ans;
    }
};

// @lc code=end
