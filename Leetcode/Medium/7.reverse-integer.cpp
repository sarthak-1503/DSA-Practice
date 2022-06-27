/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (26.74%)
 * Likes:    7486
 * Dislikes: 10007
 * Total Accepted:    2.1M
 * Total Submissions: 7.9M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 120
 * Output: 21
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        
        if(x == INT_MAX || x == INT_MIN || x == 0)
        {
            return 0;
        }
        
        int sign = x/abs(x);
        long long ans = 0;
        x = abs(x);
        
        while(x)
        {
            if(ans*10 > INT_MAX || ans*10 < INT_MIN)
            {
                return 0;
            }
            
            ans = ans*10 + (x % 10);
            x /= 10;
        }
        
        return sign*ans;
    }
};
// @lc code=end

