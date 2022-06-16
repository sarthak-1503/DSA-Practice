/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    18940
 * Dislikes: 1096
 * Total Accepted:    1.9M
 * Total Submissions: 6M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int j, k;
        int ma = 0;
        string ans = "";
        
        for(int i=0;i<n;i++)
        {
            j = i-1;
            
            while(j >= 0 && s[j] == s[i])
            {
                j--;
            }
            
            k = i+1;
            
            while(k < n && s[k] == s[i])
            {
                k++;
            }
            
            while(j >= 0 && k < n && s[j] == s[k])
            {
                j--;
                k++;
            }
            
            if(k-j-1 > ma)
            {
                ma = k-j-1;
                ans = s.substr(j+1,k-j-1);
            }
        }
        
        return ans;
    }
};
// @lc code=end

