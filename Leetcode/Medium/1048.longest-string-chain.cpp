/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 *
 * https://leetcode.com/problems/longest-string-chain/description/
 *
 * algorithms
 * Medium (57.88%)
 * Likes:    4552
 * Dislikes: 189
 * Total Accepted:    243.8K
 * Total Submissions: 412.6K
 * Testcase Example:  '["a","b","ba","bca","bda","bdca"]'
 *
 * You are given an array of words where each word consists of lowercase
 * English letters.
 * 
 * wordA is a predecessor of wordB if and only if we can insert exactly one
 * letter anywhere in wordA without changing the order of the other characters
 * to make it equal to wordB.
 * 
 * 
 * For example, "abc" is a predecessor of "abac", while "cba" is not a
 * predecessor of "bcad".
 * 
 * 
 * A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1,
 * where word1 is a predecessor of word2, word2 is a predecessor of word3, and
 * so on. A single word is trivially a word chain with k == 1.
 * 
 * Return the length of the longest possible word chain with words chosen from
 * the given list of words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["a","b","ba","bca","bda","bdca"]
 * Output: 4
 * Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * Output: 5
 * Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc",
 * "pcxbc", "pcxbcf"].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["abcd","dbqca"]
 * Output: 1
 * Explanation: The trivial word chain ["abcd"] is one of the longest word
 * chains.
 * ["abcd","dbqca"] is not a valid word chain because the ordering of the
 * letters is changed.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPredecessor(string &t, string &s)
    {
        if(s.size() != t.size() + 1)
        {
            return false;
        }

        int j = 0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == t[j])
            {
                j++;
            }
        }

        return j == t.size();
    }

    static bool compare(string &a,string &b)
    {
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        if(n == 1)
        {
            return 1;
        }

        sort(words.begin(),words.end(),compare);
        vector<long> store(n,1);
        long ans = 0;

        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(words[i].size() - words[j].size() > 1)
                {
                    break;
                }

                if(words[i].size() - words[j].size() == 1)
                {
                    if(isPredecessor(words[j],words[i]))
                    {
                        store[i] = max(store[i],store[j] + 1);
                    }
                }
            }

            ans = max(ans,store[i]);
        }

        return ans;
    }
};
// @lc code=end

