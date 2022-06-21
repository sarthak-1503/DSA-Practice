/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (57.70%)
 * Likes:    5379
 * Dislikes: 106
 * Total Accepted:    308.5K
 * Total Submissions: 530.3K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given an integer array coins representing coins of different
 * coins and an integer amount representing a total amount of money.
 *
 * Return the number of combinations that make up that amount. If that amount
 * of money cannot be made up by any combination of the coins, return 0.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 * The answer is guaranteed to fit into a signed 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: amount = 5, coins = [1,2,5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * Example 2:
 *
 *
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 *
 *
 * Example 3:
 *
 *
 * Input: amount = 10, coins = [10]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 300
 * 1 <= coins[i] <= 5000
 * All the amounts of coins are unique.
 * 0 <= amount <= 5000
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long noOfWays(int n, int amount, vector<int> &coins, vector<vector<long>> &dp)
    {
        if (n < 0 || amount < 0)
        {
            return 0;
        }

        if (dp[n][amount] != -1)
        {
            return dp[n][amount];
        }

        if (amount == 0)
        {
            return 1;
        }

        if (n == 0)
        {
            return 0;
        }

        long taken = 0, notTaken;

        notTaken = noOfWays(n - 1, amount, coins, dp);

        if (amount >= coins[n - 1])
        {
            taken = noOfWays(n, amount - coins[n - 1], coins, dp);
        }

        return dp[n][amount] = taken + notTaken;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long>> dp(n + 1, vector<long>(amount + 1, -1));

        return noOfWays(n, amount, coins, dp);
    }
};
// @lc code=end
