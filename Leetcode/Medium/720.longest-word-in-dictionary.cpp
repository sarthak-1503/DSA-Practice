/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 *
 * https://leetcode.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Medium (51.07%)
 * Likes:    1414
 * Dislikes: 1331
 * Total Accepted:    118.4K
 * Total Submissions: 231K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * Given an array of strings words representing an English Dictionary, return
 * the longest word in words that can be built one character at a time by other
 * words in words.
 * 
 * If there is more than one possible answer, return the longest word with the
 * smallest lexicographical order. If there is no answer, return the empty
 * string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["w","wo","wor","worl","world"]
 * Output: "world"
 * Explanation: The word "world" can be built one character at a time by "w",
 * "wo", "wor", and "worl".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["a","banana","app","appl","ap","apply","apple"]
 * Output: "apple"
 * Explanation: Both "apply" and "apple" can be built from other words in the
 * dictionary. However, "apple" is lexicographically smaller than "apply".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 30
 * words[i] consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool compare(string &a,string &b)
    {
        if(a.size() == b.size())
        {
            return a < b;
        }

        return a.size() < b.size();
    }

    string longestWord(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        set<string> s;
        string ans = "";
        string prefix;

        for(auto word : words)
        {
            prefix = word.substr(0,word.size()-1);
            auto ptr = s.lower_bound(prefix);

            if(word.size() == 1 || (ptr != s.end() && (*ptr) == prefix))
            {
                s.insert(word);

                if(word.size() >= ans.size())
                {
                    if(word.size() == ans.size())
                    {
                        if(word < ans)
                        {
                            ans = word;
                        }
                    }
                    else
                    {
                        ans = word;
                    }
                    
                }
            }
        }

        return ans;
    }
};
// @lc code=end

