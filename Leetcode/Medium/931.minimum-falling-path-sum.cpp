/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (67.46%)
 * Likes:    2463
 * Dislikes: 95
 * Total Accepted:    132.2K
 * Total Submissions: 195.3K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 *
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum as shown.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[-19,57],[-40,-5]]
 * Output: -59
 * Explanation: The falling path with a minimum sum is shown.
 *
 *
 *
 * Constraints:
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSum(vector<vector<int>> &matrix, int row, int col, int n, vector<vector<int>> &dp)
    {
        if (row < 0 || col < 0 || row >= n || col >= n)
        {
            return (long long)INT_MAX;
        }

        if (row == n - 1)
        {
            return dp[row][col] = matrix[row][col];
        }

        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        return dp[row][col] = matrix[row][col] +
                              min(minSum(matrix, row + 1, col, n, dp), min(minSum(matrix, row + 1, col - 1, n, dp), minSum(matrix, row + 1, col + 1, n, dp)));
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        //  Write your code here.
        int n = matrix.size();
        int mi = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            mi = min(mi, minSum(matrix, 0, i, n, dp));
        }

        return mi;
    }
};
// @lc code=end
