/*
 * @lc app=leetcode id=2249 lang=cpp
 *
 * [2249] Count Lattice Points Inside a Circle
 *
 * https://leetcode.com/problems/count-lattice-points-inside-a-circle/description/
 *
 * algorithms
 * Medium (50.14%)
 * Likes:    127
 * Dislikes: 171
 * Total Accepted:    13.4K
 * Total Submissions: 26.7K
 * Testcase Example:  '[[2,2,1]]'
 *
 * Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents
 * the center (xi, yi) and radius ri of the i^th circle drawn on a grid, return
 * the number of lattice points that are present inside at least one circle.
 * 
 * Note:
 * 
 * 
 * A lattice point is a point with integer coordinates.
 * Points that lie on the circumference of a circle are also considered to be
 * inside it.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: circles = [[2,2,1]]
 * Output: 5
 * Explanation:
 * The figure above shows the given circle.
 * The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2,
 * 3), and (3, 2) and are shown in green.
 * Other points such as (1, 1) and (1, 3), which are shown in red, are not
 * considered inside the circle.
 * Hence, the number of lattice points present inside at least one circle is
 * 5.
 * 
 * Example 2:
 * 
 * 
 * Input: circles = [[2,2,2],[3,4,1]]
 * Output: 16
 * Explanation:
 * The figure above shows the given circles.
 * There are exactly 16 lattice points which are present inside at least one
 * circle. 
 * Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= circles.length <= 200
 * circles[i].length == 3
 * 1 <= xi, yi <= 100
 * 1 <= ri <= min(xi, yi)
 * 
 * 
 */

// @lc code=start
typedef pair<int,int> pi;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n = circles.size();
        set<pi> a;
        
        for(int i=0;i<n;i++)
        {
            a.insert({circles[i][0]+circles[i][2],circles[i][1]});
            a.insert({circles[i][0]-circles[i][2],circles[i][1]});
            a.insert({circles[i][0],circles[i][1]+circles[i][2]});
            a.insert({circles[i][0],circles[i][1]-circles[i][2]});
            
            for(int j=-circles[i][2]+1;j<=circles[i][2]-1;j++)
            {
                for(int k=-circles[i][2]+1;k<=circles[i][2]-1;k++)
                {
                    int check = j*j + k*k - circles[i][2]*circles[i][2];
                    
                    if(check <= 0)
                    {
                        a.insert({j+circles[i][0],k+circles[i][1]});
                    }
                }
            }
        }
        
        return a.size();
    }
};
// @lc code=end

