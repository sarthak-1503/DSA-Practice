/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (46.45%)
 * Likes:    7751
 * Dislikes: 123
 * Total Accepted:    459.7K
 * Total Submissions: 987.5K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subsetSum(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (n < 0 || k < 0)
        {
            return false;
        }

        if (k == 0)
        {
            return dp[n][k] = true;
        }

        if (n == 0)
        {
            return dp[n][k] = false;
        }

        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }

        return dp[n][k] = subsetSum(n - 1, k, arr, dp) || subsetSum(n - 1, k - arr[n - 1], arr, dp);
    }

    bool canPartition(vector<int> &nums)
    {

        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
        {
            return false;
        }

        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));

        return subsetSum(n, sum / 2, nums, dp);
    }
};
// @lc code=end
