/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 *
 * https://leetcode.com/problems/find-unique-binary-string/description/
 *
 * algorithms
 * Medium (63.41%)
 * Likes:    601
 * Dislikes: 28
 * Total Accepted:    25.3K
 * Total Submissions: 39.9K
 * Testcase Example:  '["01","10"]'
 *
 * Given an array of strings nums containing n unique binary strings each of
 * length n, return a binary string of length n that does not appear in nums.
 * If there are multiple answers, you may return any of them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = ["01","10"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "00" would also be correct.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = ["00","01"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "10" would also be correct.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = ["111","011","001"]
 * Output: "101"
 * Explanation: "101" does not appear in nums. "000", "010", "100", and "110"
 * would also be correct.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 16
 * nums[i].length == n
 * nums[i] is either '0' or '1'.
 * All the strings of nums are unique.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void missingBinaryString(int n,int index,string curr,string &ans,map<string,int> m)
    {
        if(m.find(curr) == m.end())
        {
            ans = curr;
            return ;
        }

        if(index >= n)
        {
            return ;
        }

        for(int i=index;i<n;i++)
        {
            curr[i] = '1';
            missingBinaryString(n,i+1,curr,ans,m);
            curr[i] = '0';
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        map<string,int> m;
        string curr = "";
        string ans = "";

        for(int i=0;i<n;i++)
        {
            m[nums[i]] = 1;
            curr += '0';
        }

        missingBinaryString(n,0,curr,ans,m);

        return ans;
    }
};
// @lc code=end

