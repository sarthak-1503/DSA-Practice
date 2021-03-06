/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (39.95%)
 * Likes:    5700
 * Dislikes: 95
 * Total Accepted:    411.6K
 * Total Submissions: 1M
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it
 * will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2), because they are adjacent houses.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int solve(vector<int> &nums)
    {
        // Write your code here.
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        if (n > 1)
        {
            dp[1] = max(nums[1], nums[0]);
        }

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i], dp[i - 2] + nums[i]);

            dp[i] = max(dp[i], dp[i - 1]);
        }

        return dp[n - 1];
    }

    int rob(vector<int> &valueInHouse)
    {
        // Write your code here.
        if (valueInHouse.size() == 1)
        {
            return valueInHouse[0];
        }

        vector<int> temp, temp2;
        for (int i = 0; i < valueInHouse.size(); i++)
        {
            if (i != 0)
            {
                temp.push_back(valueInHouse[i]);
            }

            if (i != valueInHouse.size() - 1)
            {
                temp2.push_back(valueInHouse[i]);
            }
        }

        int n = temp.size();

        //     vector<long long> dp(n+1,-1);

        return max(solve(temp2), solve(temp));
    }
};
// @lc code=end
