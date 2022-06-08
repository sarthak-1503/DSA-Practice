/*
 * @lc app=leetcode id=2248 lang=cpp
 *
 * [2248] Intersection of Multiple Arrays
 *
 * https://leetcode.com/problems/intersection-of-multiple-arrays/description/
 *
 * algorithms
 * Easy (69.87%)
 * Likes:    201
 * Dislikes: 13
 * Total Accepted:    22.8K
 * Total Submissions: 32.6K
 * Testcase Example:  '[[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]'
 *
 * Given a 2D integer array nums where nums[i] is a non-empty array of distinct
 * positive integers, return the list of integers that are present in each
 * array of nums sorted in ascending order.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
 * Output: [3,4]
 * Explanation: 
 * The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] =
 * [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [[1,2,3],[4,5,6]]
 * Output: []
 * Explanation: 
 * There does not exist any integer present both in nums[0] and nums[1], so we
 * return an empty list [].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= sum(nums[i].length) <= 1000
 * 1 <= nums[i][j] <= 1000
 * All the values of nums[i] are unique.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                m[nums[i][j]]++;
            }
        }
        
        vector<int> ans;
        
        for(auto ptr : m)
        {
            if(ptr.second == n)
            {
                ans.push_back(ptr.first);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
// @lc code=end

