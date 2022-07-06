
// @lc app=leetcode id=2309 lang=cpp

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int n = s.size();
        long long store = 0;

        int j = 0, i;
        long long temp1, temp2;
        int ans = 0;
        long long c = 1;

        for (i = n - 1; i >= 0; i--)
        {
            temp2 = store + ((s[i] - '0') * c);

            if (k >= temp2)
            {
                store = temp2;
                j++;
                ans++;
                c *= 2;

                if (j == 32)
                {
                    break;
                }
            }
        }
        i--;

        while (i >= 0)
        {
            if (s[i] == '0')
            {
                ans++;
            }

            i--;
        }

        return ans;
    }
};

// @lc code=end