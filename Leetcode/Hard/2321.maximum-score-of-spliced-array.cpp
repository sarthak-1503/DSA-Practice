
// * @lc app=leetcode id=2320 lang=cpp

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> diff(n);

        for (int i = 0; i < n; i++)
        {
            diff[i] = nums1[i] - nums2[i];
        }

        long sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        long sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        long sum = 0;
        long mi = INT_MAX;
        long ma = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            sum += diff[i];

            if (sum > 0)
            {
                sum = 0;
            }
            else
            {
                mi = min(mi, sum);
            }
        }

        for (int i = 0; i < n; i++)
        {
            sum += diff[i];

            if (sum < 0)
            {
                sum = 0;
            }
            else
            {
                ma = max(ma, sum);
            }
        }

        return max(max(sum1, sum1 - mi), max(sum2, sum2 + ma));
    }
};

// @lc code=end