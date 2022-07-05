/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (48.74%)
 * Likes:    11207
 * Dislikes: 484
 * Total Accepted:    767K
 * Total Submissions: 1.6M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 1)
        {
            return n;
        }

        map<long, long> m;

        for (int i = 0; i < n; i++)
        {
            m[nums[i]] = 1;
        }

        auto itr = m.begin(), it = m.begin();
        itr++;
        long cnt = 1, ans = 1;

        for (auto ptr = itr; ptr != m.end(); ++ptr)
        {
            if (it->first + 1 == ptr->first)
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }

            it++;
        }

        ans = max(ans, cnt);

        return ans;
    }
};
// @lc code=end
