/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 *
 * https://leetcode.com/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (79.50%)
 * Likes:    2913
 * Dislikes: 136
 * Total Accepted:    117.4K
 * Total Submissions: 147.6K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * You are given an m x n integer array grid where grid[i][j] could be:
 * 
 * 
 * 1 representing the starting square. There is exactly one starting
 * square.
 * 2 representing the ending square. There is exactly one ending square.
 * 0 representing empty squares we can walk over.
 * -1 representing obstacles that we cannot walk over.
 * 
 * 
 * Return the number of 4-directional walks from the starting square to the
 * ending square, that walk over every non-obstacle square exactly once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * Output: 2
 * Explanation: We have the following two paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * Output: 4
 * Explanation: We have the following four paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[0,1],[2,0]]
 * Output: 0
 * Explanation: There is no path that walks over every empty square exactly
 * once.
 * Note that the starting and ending square can be anywhere in the grid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 20
 * 1 <= m * n <= 20
 * -1 <= grid[i][j] <= 2
 * There is exactly one starting cell and one ending cell.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

void numberOfPaths(vector<vector<int>> grid,int sx,int sy,vector<vector<int>> visited,int &ans)
{
    if(sx < 0 || sy < 0 || sx >= grid.size() || sy >= grid[0].size() || grid[sx][sy] == -1 || visited[sx][sy] == true)
    {
        return ;
    }

    
    if(sx >= 0 && sy >= 0 && sx < grid.size() && sy < grid[0].size() && grid[sx][sy] == 2)
    {
        ans++;
        cout<<"\n"<<sx<<" "<<sy<<" "<<ans<<"\n";
                
        return ;
    }

    visited[sx][sy] = true;

    numberOfPaths(grid,sx+1,sy,visited,ans);
    numberOfPaths(grid,sx,sy-1,visited,ans);
    numberOfPaths(grid,sx-1,sy,visited,ans);
    numberOfPaths(grid,sx,sy+1,visited,ans);

    cout<<sx<<" "<<sy<<"\n";

    visited[sx][sy] = false;
}

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startposx = -1;
        int startposy = -1;
        int n = grid.size();
        int index;
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            index = find(grid[i].begin(),grid[i].end(),1) - grid[i].begin();

            if(index != grid[i].size())
            {
                startposx = i;
                startposy = index;
                break;
            }
        }

        // cout<<startposx<<" "<<startposy<<"\n";

        vector<vector<int>> visited(n,vector<int> (grid[0].size(),false));
        
        numberOfPaths(grid,startposx,startposy,visited,ans);

        return ans;

    }
};
// @lc code=end

