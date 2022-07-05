
// * @lc app=leetcode id=2315 lang=cpp

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countAsterisks(string s)
    {
        int n = s.size();
        int ans = 0;
        int cntBar = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '|')
            {
                cntBar++;
            }
            else if (s[i] == '*')
            {
                if (cntBar % 2 == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// @lc code=end