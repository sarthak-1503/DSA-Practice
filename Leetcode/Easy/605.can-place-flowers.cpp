/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (33.11%)
 * Likes:    2970
 * Dislikes: 660
 * Total Accepted:    302.6K
 * Total Submissions: 913.7K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * You have a long flowerbed in which some of the plots are planted, and some
 * are not. However, flowers cannot be planted in adjacent plots.
 *
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty
 * and 1 means not empty, and an integer n, return if n new flowers can be
 * planted in the flowerbed without violating the no-adjacent-flowers rule.
 *
 *
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= flowerbed.length <= 2 * 10^4
 * flowerbed[i] is 0 or 1.
 * There are no two adjacent flowers in flowerbed.
 * 0 <= n <= flowerbed.length
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int N = flowerbed.size();
        int c = 0;

        for (int i = 0; i < N; i++)
        {
            if (c == n)
            {
                return true;
            }

            if (flowerbed[i] == 0)
            {
                if (N == 1 || (i == 0 && flowerbed[i + 1] == 0) || (i == N - 1 && flowerbed[i - 1] == 0) || (i > 0 && i < N - 1 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0))
                {
                    cout << i << " ";
                    c++;
                    i++;
                }

                if (c == n)
                {
                    return true;
                }
            }
        }

        if (c == n)
        {
            return true;
        }

        return false;
    }
};
// @lc code=end
