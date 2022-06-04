/*
 * @lc app=leetcode id=2271 lang=cpp
 *
 * [2271] Maximum White Tiles Covered by a Carpet
 *
 * https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/
 *
 * algorithms
 * Medium (28.04%)
 * Likes:    381
 * Dislikes: 24
 * Total Accepted:    7.4K
 * Total Submissions: 25.5K
 * Testcase Example:  '[[1,5],[10,11],[12,18],[20,25],[30,32]]\n10'
 *
 * You are given a 2D integer array tiles where tiles[i] = [li, ri] represents
 * that every tile j in the range li <= j <= ri is colored white.
 * 
 * You are also given an integer carpetLen, the length of a single carpet that
 * can be placed anywhere.
 * 
 * Return the maximum number of white tiles that can be covered by the
 * carpet.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
 * Output: 9
 * Explanation: Place the carpet starting on tile 10. 
 * It covers 9 white tiles, so we return 9.
 * Note that there may be other places where the carpet covers 9 white tiles.
 * It can be shown that the carpet cannot cover more than 9 white tiles.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tiles = [[10,11],[1,1]], carpetLen = 2
 * Output: 2
 * Explanation: Place the carpet starting on tile 10. 
 * It covers 2 white tiles, so we return 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= tiles.length <= 5 * 10^4
 * tiles[i].length == 2
 * 1 <= li <= ri <= 10^9
 * 1 <= carpetLen <= 10^9
 * The tiles are non-overlapping.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    static bool compare(vector<int> a,vector<int> b)
    {
        return a[0] < b[0];
    }
    
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(),tiles.end());
        vector<long> a(n);
        vector<long> cnt(n);
        cnt[0] = tiles[0][1] - tiles[0][0] + 1;
        long ans = min(cnt[0],(long)carpetLen);
        
        for(int i=0;i<n;i++)
        {
            a[i] = tiles[i][0];
        }
        
        for(int i=1;i<n;i++)
        {
            cnt[i] += cnt[i-1] + (tiles[i][1] - tiles[i][0] + 1);
        }
        
        for(int i=0;i<n;i++)
        {
            long index = lower_bound(a.begin()+i,a.end(),a[i] + carpetLen-1) - a.begin();
            
            if(i)
            {
                ans = max(ans,cnt[index-1]-cnt[i-1]-max((long)tiles[index-1][1]-a[i]-carpetLen+1,(long)0));
            }
            else
            {
                if(index)
                {
                    if(index < n && a[index] == a[i] + carpetLen-1)
                    {
                        ans = max(ans,cnt[index]-max((long)tiles[index][1]-a[i]-carpetLen+1,(long)0));
                    }
                    else
                    {
                        ans = max(ans,cnt[index-1]-max((long)tiles[index-1][1]-a[i]-carpetLen+1,(long)0));
                    }
                }
            }
            
            cout<<ans<<" "<<i<<"\n";
        }
        
        return ans;
    }
};
// @lc code=end

