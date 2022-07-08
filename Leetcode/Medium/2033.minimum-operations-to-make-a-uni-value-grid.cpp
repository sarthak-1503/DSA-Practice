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
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long noOfOperations(int med, vector<vector<int>> &grid, int m, int n, int x)
    {
        if (med == INT_MAX)
        {
            return INT_MAX;
        }

        long ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(med - grid[i][j]) % x)
                {
                    return -1;
                }

                ans += abs(med - grid[i][j]) / x;
            }
        }

        return ans;
    }

    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> store;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                store.push_back(grid[i][j]);
            }
        }

        sort(store.begin(), store.end());

        int median = store[store.size() / 2];
        int med2 = INT_MAX;

        if ((m * n) % 2 == 0)
        {
            med2 = store[store.size() / 2 - 1];
        }

        return min(noOfOperations(med2, grid, m, n, x), noOfOperations(median, grid, m, n, x));
    }
};
// @lc code=end
