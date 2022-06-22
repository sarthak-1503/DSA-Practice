/*
 * @lc app=leetcode id=2213 lang=cpp
 *
 * [2213] Longest Substring of One Repeating Character
 *
 * https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/
 *
 * algorithms
 * Hard (28.51%)
 * Likes:    143
 * Dislikes: 70
 * Total Accepted:    2.5K
 * Total Submissions: 8.2K
 * Testcase Example:  '"babacc"\n"bcb"\n[1,3,3]'
 *
 * You are given a 0-indexed string s. You are also given a 0-indexed string
 * queryCharacters of length k and a 0-indexed array of integer indices
 * queryIndices of length k, both of which are used to describe k queries.
 *
 * The i^th query updates the character in s at index queryIndices[i] to the
 * character queryCharacters[i].
 *
 * Return an array lengths of length k where lengths[i] is the length of the
 * longest substring of s consisting of only one repeating character after the
 * i^th query is performed.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
 * Output: [3,3,4]
 * Explanation:
 * - 1^st query updates s = "bbbacc". The longest substring consisting of one
 * repeating character is "bbb" with length 3.
 * - 2^nd query updates s = "bbbccc".
 * ⁠ The longest substring consisting of one repeating character can be "bbb"
 * or "ccc" with length 3.
 * - 3^rd query updates s = "bbbbcc". The longest substring consisting of one
 * repeating character is "bbbb" with length 4.
 * Thus, we return [3,3,4].
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
 * Output: [2,3]
 * Explanation:
 * - 1^st query updates s = "abazz". The longest substring consisting of one
 * repeating character is "zz" with length 2.
 * - 2^nd query updates s = "aaazz". The longest substring consisting of one
 * repeating character is "aaa" with length 3.
 * Thus, we return [2,3].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * k == queryCharacters.length == queryIndices.length
 * 1 <= k <= 10^5
 * queryCharacters consists of lowercase English letters.
 * 0 <= queryIndices[i] < s.length
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {
        int n = s.size(), k = queryCharacters.size();
        map<char,map<int,int>> m;
        vector<int> ans;
        int start = -1, end = -1, c = 1, cntmax = 0, startmax = -1, endmax = -1;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                c++;

                if (c == 1)
                {
                    start = i;
                    end = i + 1;
                }
            }
            else
            {
                if (c > cntmax)
                {
                    cntmax = c;
                    startmax = start;
                    endmax = end;
                }

                c = 1;
                start = -1;
                end = -1;
            }

            m[s[i]][i] = 1;
        }

        if (c > cntmax)
        {
            cntmax = c;
            startmax = start;
            endmax = end;
        }

        m[s.back()][n-1] = 1;

        for(auto arrindex : queryIndices)
        {
            m[s[arrindex]].erase(arrindex);
            m[queryCharacters[arrindex]][arrindex] = 1;
            int maxLen = 0, curr = arrindex;
            auto temp = m[queryCharacters[arrindex]];
            start = arrindex;
            end = arrindex;
            auto findIndex = temp.find(arrindex);
            int j = arrindex;
            auto itr = temp.begin();
            itr--;

            for(auto ptr=findIndex;ptr!= itr;ptr--)
            {
                if(ptr != findIndex)
                {
                    if(curr - ptr->first == 1)
                    {
                        start--;
                    }
                    else
                    {
                        break;
                    }

                    curr = ptr->first;
                }
            }

            curr = arrindex;

            for(auto ptr=findIndex;ptr!= temp.end();ptr++)
            {
                if(ptr != findIndex)
                {
                    if(ptr->first - curr == 1)
                    {
                        end++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            maxLen = max(maxLen,end-start+1);

            if(arrindex >= startmax && arrindex <= endmax)
            {
                maxLen = max(maxLen, arrindex-startmax);
                maxLen = max(maxLen,endmax-arrindex);
            }
            else
            {
                maxLen = max(maxLen,endmax-startmax+1);
            }

            ans.push_back(maxLen);
        }

        return ans;

    }
};
// @lc code=end
