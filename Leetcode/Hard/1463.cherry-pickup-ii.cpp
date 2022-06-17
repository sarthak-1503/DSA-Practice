/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 *
 * https://leetcode.com/problems/cherry-pickup-ii/description/
 *
 * algorithms
 * Hard (70.70%)
 * Likes:    2104
 * Dislikes: 22
 * Total Accepted:    61.3K
 * Total Submissions: 86.7K
 * Testcase Example:  '[[3,1,1],[2,5,1],[1,5,5],[2,1,1]]'
 *
 * You are given a rows x cols matrix grid representing a field of cherries
 * where grid[i][j] represents the number of cherries that you can collect from
 * the (i, j) cell.
 * 
 * You have two robots that can collect cherries for you:
 * 
 * 
 * Robot #1 is located at the top-left corner (0, 0), and
 * Robot #2 is located at the top-right corner (0, cols - 1).
 * 
 * 
 * Return the maximum number of cherries collection using both robots by
 * following the rules below:
 * 
 * 
 * From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or
 * (i + 1, j + 1).
 * When any robot passes through a cell, It picks up all cherries, and the cell
 * becomes an empty cell.
 * When both robots stay in the same cell, only one takes the cherries.
 * Both robots cannot move outside of the grid at any moment.
 * Both robots should reach the bottom row in grid.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
 * Output: 24
 * Explanation: Path of robot #1 and #2 are described in color green and blue
 * respectively.
 * Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
 * Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
 * Total of cherries: 12 + 12 = 24.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid =
 * [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
 * Output: 28
 * Explanation: Path of robot #1 and #2 are described in color green and blue
 * respectively.
 * Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
 * Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
 * Total of cherries: 17 + 11 = 28.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * rows == grid.length
 * cols == grid[i].length
 * 2 <= rows, cols <= 70
 * 0 <= grid[i][j] <= 100
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int collectMax(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
{
    if(i < 0 || i >= r || j1 < 0 || j1 >= c || j2 < 0 | j2 >= c)
    {
        return -1e8;
    }
    
    if(dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    
    if(i == r - 1)
    {
        if(j1 == j2)
        {
            return dp[i][j1][j2] = grid[i][j1];
        }
        
        return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
    }
    
    int ma = 0;
    
    for(int z=-1;z<=1;z++)
    {
        for(int k=-1;k<=1;k++)
        {
            if(j1 == j2)
            {
                ma = max(ma,grid[i][j1] + collectMax(i+1,j1+z,j2+k,r,c,grid,dp));
            }
            else
            {
                ma = max(ma,grid[i][j1] + grid[i][j2] + collectMax(i+1,j1+z,j2+k,r,c,grid,dp));
            }
        }
    }
    
    return dp[i][j1][j2] = ma;
    
}

    int cherryPickup(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int> (c,-1)));
    return collectMax(0,0,c-1,r,c,grid,dp);
    }
};
// @lc code=end

