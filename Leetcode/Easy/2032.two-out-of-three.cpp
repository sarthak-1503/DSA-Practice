/*
 * @lc app=leetcode id=2032 lang=cpp
 *
 * [2032] Two Out of Three
 *
 * https://leetcode.com/problems/two-out-of-three/description/
 *
 * algorithms
 * Easy (72.99%)
 * Likes:    339
 * Dislikes: 29
 * Total Accepted:    30.8K
 * Total Submissions: 42.3K
 * Testcase Example:  '[1,1,3,2]\n[2,3]\n[3]'
 *
 * Given three integer arrays nums1, nums2, and nums3, return a distinct array
 * containing all the values that are present in at least two out of the three
 * arrays. You may return the values in any order.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
 * Output: [3,2]
 * Explanation: The values that are present in at least two arrays are:
 * - 3, in all three arrays.
 * - 2, in nums1 and nums2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
 * Output: [2,3,1]
 * Explanation: The values that are present in at least two arrays are:
 * - 2, in nums2 and nums3.
 * - 3, in nums1 and nums2.
 * - 1, in nums1 and nums3.
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
 * Output: []
 * Explanation: No value is present in at least two arrays.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length, nums3.length <= 100
 * 1 <= nums1[i], nums2[j], nums3[k] <= 100
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        map<int, int> m1, m2, m3;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            m1[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            m2[nums2[i]]++;
        }

        for (int i = 0; i < nums3.size(); i++)
        {
            m3[nums3[i]]++;
        }

        auto ptr = m1.begin();

        while (!m1.empty())
        {

            ptr = m1.begin();

            if (m2.find(ptr->first) != m2.end())
            {
                ans.push_back(ptr->first);
                m2.erase(ptr->first);
            }

            if (m3.find(ptr->first) != m3.end())
            {
                if (ans.empty() || ans.back() != ptr->first)
                {
                    ans.push_back(ptr->first);
                }

                m3.erase(ptr->first);
            }

            m1.erase(ptr->first);
        }

        while (!m2.empty())
        {
            ptr = m2.begin();

            if (m3.find(ptr->first) != m3.end())
            {
                ans.push_back(ptr->first);
                m3.erase(ptr->first);
            }

            m2.erase(ptr->first);
        }

        return ans;
    }
};
// @lc code=end
