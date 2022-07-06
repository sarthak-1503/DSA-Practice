
// @lc app=leetcode id=2309 lang=cpp

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string greatestLetter(string s)
    {
        vector<int> lower(26, 0), upper(26, 0);
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 97 && s[i] <= 122)
            {
                lower[s[i] - 'a']++;
            }
            else if (s[i] >= 65 && s[i] <= 90)
            {
                upper[s[i] - 'A']++;
            }
        }

        for (int i = 25; i >= 0; i--)
        {
            if (upper[i] && lower[i])
            {
                string temp = "";
                temp += (char)(i + 65);
                return temp;
            }
        }

        return "";
    }
};

// @lc code=end