
// * @lc app=leetcode id=2319 lang=cpp
// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (i + j == grid.size() - 1 || i == j)
                {
                    if (grid[i][j] == 0)
                    {
                        return false;
                    }
                }
                else
                {
                    if (grid[i][j])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

// @lc code=end