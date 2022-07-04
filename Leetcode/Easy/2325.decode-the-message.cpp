
// @lc app=leetcode id=2325 lang=cpp

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        int n = key.size();
        vector<int> store(26, -1);
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            if (key[i] >= 97 && key[i] <= 122)
            {
                if (store[key[i] - 'a'] == -1)
                {
                    store[key[i] - 'a'] = c;
                    c++;
                }
            }
        }

        for (int i = 0; i < message.size(); i++)
        {
            if (message[i] >= 97 && message[i] <= 122)
            {
                message[i] = (char)(store[message[i] - 'a'] + 97);
            }
        }

        return message;
    }
};

// @lc code=end