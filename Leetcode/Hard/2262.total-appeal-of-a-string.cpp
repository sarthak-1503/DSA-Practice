/*
 * @lc app=leetcode id=2262 lang=cpp
 *
 * [2262] Total Appeal of A String
 *
 * https://leetcode.com/problems/total-appeal-of-a-string/description/
 *
 * algorithms
 * Hard (51.97%)
 * Likes:    408
 * Dislikes: 11
 * Total Accepted:    9.4K
 * Total Submissions: 17.6K
 * Testcase Example:  '"abbca"'
 *
 * The appeal of a string is the number of distinct characters found in the
 * string.
 * 
 * 
 * For example, the appeal of "abbca" is 3 because it has 3 distinct
 * characters: 'a', 'b', and 'c'.
 * 
 * 
 * Given a string s, return the total appeal of all of its substrings.
 * 
 * A substring is a contiguous sequence of characters within a string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abbca"
 * Output: 28
 * Explanation: The following are the substrings of "abbca":
 * - Substrings of length 1: "a", "b", "b", "c", "a" have an appeal of 1, 1, 1,
 * 1, and 1 respectively. The sum is 5.
 * - Substrings of length 2: "ab", "bb", "bc", "ca" have an appeal of 2, 1, 2,
 * and 2 respectively. The sum is 7.
 * - Substrings of length 3: "abb", "bbc", "bca" have an appeal of 2, 2, and 3
 * respectively. The sum is 7.
 * - Substrings of length 4: "abbc", "bbca" have an appeal of 3 and 3
 * respectively. The sum is 6.
 * - Substrings of length 5: "abbca" has an appeal of 3. The sum is 3.
 * The total sum is 5 + 7 + 7 + 6 + 3 = 28.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "code"
 * Output: 20
 * Explanation: The following are the substrings of "code":
 * - Substrings of length 1: "c", "o", "d", "e" have an appeal of 1, 1, 1, and
 * 1 respectively. The sum is 4.
 * - Substrings of length 2: "co", "od", "de" have an appeal of 2, 2, and 2
 * respectively. The sum is 6.
 * - Substrings of length 3: "cod", "ode" have an appeal of 3 and 3
 * respectively. The sum is 6.
 * - Substrings of length 4: "code" has an appeal of 4. The sum is 4.
 * The total sum is 4 + 6 + 6 + 4 = 20.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

long long countNumberOfSubstrings(vector<int> a,long long n)
{
    long long total = (n*(n+1))/2;
    long long cnt = 0;
    
    for(int i=0;i<a.size()-1;i++)
    {
        cnt += ((a[i+1]-a[i]-1)*(a[i+1]-a[i]))/2;
    }
    
    cnt += (a[0]*(a[0]+1))/2;
    cnt += ((n-a.back()-1)*(n-a.back()))/2;
    
    return total - cnt;
}

class Solution {
public:
    long long appealSum(string s) {
        long long n = s.size();
        map<char,vector<int>> m;
        
        for(int i=0;i<n;i++)
        {
            m[s[i]].push_back(i);
        }
        
        long long ans = 0;
        
        for(auto ptr : m)
        {
            ans += countNumberOfSubstrings(ptr.second,n);
        }
        
        return ans;
    }
};
// @lc code=end

