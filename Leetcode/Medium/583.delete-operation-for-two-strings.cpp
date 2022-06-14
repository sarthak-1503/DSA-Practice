/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (55.98%)
 * Likes:    3975
 * Dislikes: 59
 * Total Accepted:    161.8K
 * Total Submissions: 277.9K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings word1 and word2, return the minimum number of steps
 * required to make word1 and word2 the same.
 * 
 * In one step, you can delete exactly one character in either string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "sea", word2 = "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "leetcode", word2 = "etco"
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 500
 * word1 and word2 consist of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestCommonSubseq(string &word1,string &word2,int m,int n,vector<vector<int>> &dp)
    {
        if(!m || !n)
        {
            return 0;
        }

        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }

        if(word1[m-1] == word2[n-1])
        {
            return dp[m][n] = 1 + longestCommonSubseq(word1,word2,m-1,n-1,dp);
        }

        return dp[m][n] = max(longestCommonSubseq(word1,word2,m-1,n-1,dp),max(longestCommonSubseq(word1,word2,m,n-1,dp),longestCommonSubseq(word1,word2,m-1,n,dp)));
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1,-1));

        return word1.size() + word2.size() - 2*longestCommonSubseq(word1,word2,word1.size(),word2.size(),dp);
    }
};
// @lc code=end

