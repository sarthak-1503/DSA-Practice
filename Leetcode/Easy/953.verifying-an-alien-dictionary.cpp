/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 *
 * https://leetcode.com/problems/verifying-an-alien-dictionary/description/
 *
 * algorithms
 * Easy (52.54%)
 * Likes:    2879
 * Dislikes: 950
 * Total Accepted:    357K
 * Total Submissions: 679.2K
 * Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
 *
 * In an alien language, surprisingly, they also use English lowercase letters,
 * but possibly in a different order. The order of the alphabet is some
 * permutation of lowercase letters.
 * 
 * Given a sequence of words written in the alien language, and the order of
 * the alphabet, return true if and only if the given words are sorted
 * lexicographically in this alien language.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence is
 * sorted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] >
 * words[1], hence the sequence is unsorted.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string
 * is shorter (in size.) According to lexicographical rules "apple" > "app",
 * because 'l' > '∅', where '∅' is defined as the blank character which is less
 * than any other character (More info).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * All characters in words[i] and order are English lowercase letters.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

bool lexiSorted(string &a,string &b)
{
    int n = min(a.size(),b.size());
    int i;

    for(i=0;i<n;i++)
    {
        if(a[i] < b[i])
        {
            return true;
        }
        else if(a[i] > b[i])
        {
            return false;
        }
    }

    return a.size() <= b.size();
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> store(26,-1);

        for(int i=0;i<26;i++)
        {
            store[order[i]-'a'] = i;
        }

        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                words[i][j] = (char)(store[words[i][j]-'a'] + 97);
            }
        }

        for(int i=0;i<words.size()-1;i++)
        {
            if(!lexiSorted(words[i],words[i+1]))
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

