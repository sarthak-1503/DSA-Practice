/*
 * @lc app=leetcode id=2255 lang=cpp
 *
 * [2255] Count Prefixes of a Given String
 *
 * https://leetcode.com/problems/count-prefixes-of-a-given-string/description/
 *
 * algorithms
 * Easy (71.92%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    15.7K
 * Total Submissions: 21.8K
 * Testcase Example:  '["a","b","c","ab","bc","abc"]\n"abc"'
 *
 * You are given a string array words and a string s, where words[i] and s
 * comprise only of lowercase English letters.
 * 
 * Return the number of strings in words that are a prefix of s.
 * 
 * A prefix of a string is a substring that occurs at the beginning of the
 * string. A substring is a contiguous sequence of characters within a
 * string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
 * Output: 3
 * Explanation:
 * The strings in words which are a prefix of s = "abc" are:
 * "a", "ab", and "abc".
 * Thus the number of strings in words which are a prefix of s is 3.
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["a","a"], s = "aa"
 * Output: 2
 * Explanation:
 * Both of the strings are a prefix of s. 
 * Note that the same string can occur multiple times in words, and it should
 * be counted each time.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length, s.length <= 10
 * words[i] and s consist of lowercase English letters only.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = s.size();
        string temp = "";
        map<string,int> m;
        int ans = 0;
        
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            temp += s[i];
            ans += m[temp];
        }
        
        return ans;
    }
};
// @lc code=end

