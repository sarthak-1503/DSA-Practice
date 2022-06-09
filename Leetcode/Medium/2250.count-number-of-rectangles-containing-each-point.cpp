/*
 * @lc app=leetcode id=2250 lang=cpp
 *
 * [2250] Count Number of Rectangles Containing Each Point
 *
 * https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/
 *
 * algorithms
 * Medium (31.61%)
 * Likes:    282
 * Dislikes: 98
 * Total Accepted:    8.1K
 * Total Submissions: 25.3K
 * Testcase Example:  '[[1,2],[2,3],[2,5]]\n[[2,1],[1,4]]'
 *
 * You are given a 2D integer array rectangles where rectangles[i] = [li, hi]
 * indicates that i^th rectangle has a length of li and a height of hi. You are
 * also given a 2D integer array points where points[j] = [xj, yj] is a point
 * with coordinates (xj, yj).
 * 
 * The i^th rectangle has its bottom-left corner point at the coordinates (0,
 * 0) and its top-right corner point at (li, hi).
 * 
 * Return an integer array count of length points.length where count[j] is the
 * number of rectangles that contain the j^th point.
 * 
 * The i^th rectangle contains the j^th point if 0 <= xj <= li and 0 <= yj <=
 * hi. Note that points that lie on the edges of a rectangle are also
 * considered to be contained by that rectangle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
 * Output: [2,1]
 * Explanation: 
 * The first rectangle contains no points.
 * The second rectangle contains only the point (2, 1).
 * The third rectangle contains the points (2, 1) and (1, 4).
 * The number of rectangles that contain the point (2, 1) is 2.
 * The number of rectangles that contain the point (1, 4) is 1.
 * Therefore, we return [2, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
 * Output: [1,3]
 * Explanation:
 * The first rectangle contains only the point (1, 1).
 * The second rectangle contains only the point (1, 1).
 * The third rectangle contains the points (1, 3) and (1, 1).
 * The number of rectangles that contain the point (1, 3) is 1.
 * The number of rectangles that contain the point (1, 1) is 3.
 * Therefore, we return [1, 3].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= rectangles.length, points.length <= 5 * 10^4
 * rectangles[i].length == points[j].length == 2
 * 1 <= li, xj <= 10^9
 * 1 <= hi, yj <= 100
 * All the rectangles are unique.
 * All the points are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n = points.size();
        vector<int> ans(n,0);
        map<int,vector<int>> m;
        sort(rectangles.begin(),rectangles.end());
        
        for(int i=0;i<rectangles.size();i++)
        {
            m[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            auto it = m.lower_bound(points[i][1]);
            
            while(it != m.end())
            {
                int index = lower_bound(it->second.begin(),it->second.end(),points[i][0]) - it->second.begin();
                
                ans[i] += (it->second.size()-index);
                it++;
            }
        }
        
        return ans;
    }
};
// @lc code=end

