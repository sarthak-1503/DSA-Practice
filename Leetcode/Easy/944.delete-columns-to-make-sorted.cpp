/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        int ans = 0, j;
        
        for(int i=0;i<m;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(strs[j][i] > strs[j+1][i])
                {
                    break;
                }
            }
            
            if(j < n-1)
            {
                ans++;
            }
            
        }
        
        return ans;
    }
};
// @lc code=end

