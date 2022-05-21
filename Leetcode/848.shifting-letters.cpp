/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 *
 * https://leetcode.com/problems/shifting-letters/description/
 *
 * algorithms
 * Medium (45.45%)
 * Likes:    870
 * Dislikes: 96
 * Total Accepted:    72.6K
 * Total Submissions: 159.7K
 * Testcase Example:  '"abc"\n[3,5,9]'
 *
 * You are given a string s of lowercase English letters and an integer array
 * shifts of the same length.
 * 
 * Call the shift() of a letter, the next letter in the alphabet, (wrapping
 * around so that 'z' becomes 'a').
 * 
 * 
 * For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
 * 
 * 
 * Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x
 * times.
 * 
 * Return the final string after all such shifts to s are applied.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc", shifts = [3,5,9]
 * Output: "rpl"
 * Explanation: We start with "abc".
 * After shifting the first 1 letters of s by 3, we have "dbc".
 * After shifting the first 2 letters of s by 5, we have "igc".
 * After shifting the first 3 letters of s by 9, we have "rpl", the answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaa", shifts = [1,2,3]
 * Output: "gfd"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * shifts.length == s.length
 * 0 <= shifts[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();

        for(int i=n-2;i>=0;i--)
        {
            shifts[i] = (shifts[i] + shifts[i+1]) % 26;
        }

        for(int i=0;i<n;i++)
        {
            s[i] = (char)(((s[i] - 'a') + shifts[i]) % 26 + 97);
        }

        return s;
    }
};
// @lc code=end

