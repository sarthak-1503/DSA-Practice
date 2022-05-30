/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 *
 * https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
 *
 * algorithms
 * Medium (70.58%)
 * Likes:    437
 * Dislikes: 1396
 * Total Accepted:    41.4K
 * Total Submissions: 58.6K
 * Testcase Example:  '["abcd","cdab","cbad","xyzz","zzxy","zzyx"]'
 *
 * You are given an array of strings of the same length words.
 * 
 * In one move, you can swap any two even indexed characters or any two odd
 * indexed characters of a string words[i].
 * 
 * Two strings words[i] and words[j] are special-equivalent if after any number
 * of moves, words[i] == words[j].
 * 
 * 
 * For example, words[i] = "zzxy" and words[j] = "xyzz" are special-equivalent
 * because we may make the moves "zzxy" -> "xzzy" -> "xyzz".
 * 
 * 
 * A group of special-equivalent strings from words is a non-empty subset of
 * words such that:
 * 
 * 
 * Every pair of strings in the group are special equivalent, and
 * The group is the largest size possible (i.e., there is not a string words[i]
 * not in the group such that words[i] is special-equivalent to every string in
 * the group).
 * 
 * 
 * Return the number of groups of special-equivalent strings from words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
 * Output: 3
 * Explanation: 
 * One group is ["abcd", "cdab", "cbad"], since they are all pairwise special
 * equivalent, and none of the other strings is all pairwise special equivalent
 * to these.
 * The other two groups are ["xyzz", "zzxy"] and ["zzyx"].
 * Note that in particular, "zzxy" is not special equivalent to "zzyx".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["abc","acb","bac","bca","cab","cba"]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 20
 * words[i] consist of lowercase English letters.
 * All the strings are of the same length.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        map<string,int> m;

        for(int i=0;i<n;i++)
        {
            string first = "";
            string second = "";

            for(int j=0;j<words[i].size();j++)
            {
                if(j % 2 == 0)
                {
                    first += words[i][j];
                }
                else
                {
                    second += words[i][j];
                }
            }

            sort(first.begin(),first.end());
            sort(second.begin(),second.end());

            for(int j=0;j<words[i].size();j++)
            {
                if(j % 2 == 0)
                {
                    words[i][j] = first[j/2];
                }
                else
                {
                    words[i][j] = second[(j-1)/2];
                }
            }

            m[words[i]] = 1;
        }

        return m.size();
    }
};
// @lc code=end

