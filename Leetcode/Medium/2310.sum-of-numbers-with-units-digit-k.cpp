
// @lc app=leetcode id=2309 lang=cpp

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumNumbers(int num, int k)
    {

        if (num == 0)
        {
            return 0;
        }

        if (num % 10 == k)
        {
            return 1;
        }

        if (k == 0)
        {
            k = 10;
        }

        int i = 0;
        int ans = INT_MAX;

        while (num > 10 * i)
        {
            if ((num - 10 * i) % k == 0)
            {
                cout << i << " ";
                ans = min(ans, (num - 10 * i) / k);
            }

            i++;
        }

        if (ans == INT_MAX)
        {
            ans = -1;
        }

        return ans;
    }
};

// @lc code=end