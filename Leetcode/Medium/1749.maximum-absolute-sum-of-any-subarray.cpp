/*
 * @lc app=leetcode id=1749 lang=cpp
 *
 * [1749] Maximum Absolute Sum of Any Subarray
 *
 * https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/
 *
 * algorithms
 * Medium (57.13%)
 * Likes:    748
 * Dislikes: 11
 * Total Accepted:    22.7K
 * Total Submissions: 39.6K
 * Testcase Example:  '[1,-3,2,3,-4]'
 *
 * You are given an integer array nums. The absolute sum of a subarray [numsl,
 * numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 +
 * numsr).
 * 
 * Return the maximum absolute sum of any (possibly empty) subarray of nums.
 * 
 * Note that abs(x) is defined as follows:
 * 
 * 
 * If x is a negative integer, then abs(x) = -x.
 * If x is a non-negative integer, then abs(x) = x.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,-3,2,3,-4]
 * Output: 5
 * Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,-5,1,-4,3,-2]
 * Output: 8
 * Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8)
 * = 8.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ma = 0;
        int mi = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            if(sum < 0)
            {
                sum = 0;
            }
            else
            {
                ma = max(ma,sum);
            }
        }

        sum = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            if(sum >= 0)
            {
                sum = 0;
            }
            else
            {
                mi = min(mi,sum);
            }
        }

        return max(ma,abs(mi));
    }
};
// @lc code=end

