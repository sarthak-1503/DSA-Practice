/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.42%)
 * Likes:    7120
 * Dislikes: 267
 * Total Accepted:    363.7K
 * Total Submissions: 801.6K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given an integer numsay nums and an integer target.
 *
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the
 * integers.
 *
 *
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
 * and concatenate them to build the expression "+2-1".
 *
 *
 * Return the number of different expressions that you can build, which
 * evaluates to target.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,1,1], target = 3
 * Output: 5
 * Explanation: There are 5 ways to assign symbols to make the sum of nums be
 * target 3.
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], target = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));
        int countZero = 0;
        dp[0][0] = 1;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum / 2; j++)
            {
                if (j == 0)
                {
                    if (i > 0 && nums[i - 1] == 0)
                    {
                        countZero++;
                    }

                    dp[i][j] = pow(2, countZero);
                }
                else
                {
                    if (i > 0)
                    {
                        dp[i][j] += dp[i - 1][j];

                        if (j >= nums[i - 1])
                        {
                            dp[i][j] += dp[i - 1][j - nums[i - 1]];
                        }
                    }
                }
            }
        }

        int ans = 0;

        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[n][i] && abs(2 * i - sum) == abs(target))
            {
                ans += dp[n][i];
            }
        }

        return ans;
    }
};
// @lc code=end
