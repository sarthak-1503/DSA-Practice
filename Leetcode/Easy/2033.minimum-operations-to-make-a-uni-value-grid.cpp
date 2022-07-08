/*
 * @lc app=leetcode id=2033 lang=cpp
 *
 * [2033] Minimum Operations to Make a Uni-Value Grid
 *
 * https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/
 *
 * algorithms
 * Medium (50.79%)
 * Likes:    368
 * Dislikes: 30
 * Total Accepted:    15.4K
 * Total Submissions: 30K
 * Testcase Example:  '[[2,4],[6,8]]\n2'
 *
 * You are given a 2D integer grid of size m x n and an integer x. In one
 * operation, you can add x to or subtract x from any element in the grid.
 *
 * A uni-value grid is a grid where all the elements of it are equal.
 *
 * Return the minimum number of operations to make the grid uni-value. If it is
 * not possible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,4],[6,8]], x = 2
 * Output: 4
 * Explanation: We can make every element equal to 4 by doing the following:
 * - Add x to 2 once.
 * - Subtract x from 6 once.
 * - Subtract x from 8 twice.
 * A total of 4 operations were used.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,5],[2,3]], x = 1
 * Output: 5
 * Explanation: We can make every element equal to 3.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,2],[3,4]], x = 2
 * Output: -1
 * Explanation: It is impossible to make every element equal.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10^5
 * 1 <= m * n <= 10^5
 * 1 <= x, grid[i][j] <= 10^4
 *
 *
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long noOfOperations(int avg, vector<vector<int>> &grid, int m, int n, int x)
    {
        long ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(avg - grid[i][j]) % x)
                {
                    return INT_MAX;
                }

                ans += abs(avg - grid[i][j]) / x;
            }
        }

        return ans;
    }

    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size();
        int n = grid[0].size();

        long even = 0;
        long sum = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += grid[i][j];
                even += (1 - grid[i][j] % 2);
            }
        }

        if (x % 2 == 0 && (even != (long)m * n && even != 0))
        {
            cout << "here\n";
            return -1;
        }

        if (sum % (m * n))
        {
            long ans = min(noOfOperations(sum / (m * n), grid, m, n, x), min(noOfOperations(sum / (m * n) - 1, grid, m, n, x), noOfOperations(sum / (m * n) + 1, grid, m, n, x)));

            if (ans == INT_MAX)
            {
                return -1;
            }

            return ans;
        }

        long ans = noOfOperations(sum / (m * n), grid, m, n, x);

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};
// @lc code=end
