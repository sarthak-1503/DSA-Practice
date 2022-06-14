/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (59.46%)
 * Likes:    7533
 * Dislikes: 105
 * Total Accepted:    722.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 *
 *
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSum(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (m == 0 || n == 0)
        {
            return INT_MAX;
        }

        if (m == 1 && n == 1)
        {
            return dp[m][n] = grid[m - 1][n - 1];
        }

        if (dp[m][n] != INT_MAX)
        {
            return dp[m][n];
        }

        return dp[m][n] = min(minSum(m - 1, n, grid, dp), minSum(m, n - 1, grid, dp)) + grid[m - 1][n - 1];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        return minSum(m, n, grid, dp);
    }
};
// @lc code=end
