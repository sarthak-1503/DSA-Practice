/*
 * @lc app=leetcode id=2231 lang=cpp
 *
 * [2231] Largest Number After Digit Swaps by Parity
 *
 * https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/
 *
 * algorithms
 * Easy (57.92%)
 * Likes:    212
 * Dislikes: 184
 * Total Accepted:    19.9K
 * Total Submissions: 34K
 * Testcase Example:  '1234'
 *
 * You are given a positive integer num. You may swap any two digits of num
 * that have the same parity (i.e. both odd digits or both even digits).
 * 
 * Return the largest possible value of num after any number of swaps.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 1234
 * Output: 3412
 * Explanation: Swap the digit 3 with the digit 1, this results in the number
 * 3214.
 * Swap the digit 2 with the digit 4, this results in the number 3412.
 * Note that there may be other sequences of swaps but it can be shown that
 * 3412 is the largest possible number.
 * Also note that we may not swap the digit 4 with the digit 1 since they are
 * of different parities.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 65875
 * Output: 87655
 * Explanation: Swap the digit 8 with the digit 6, this results in the number
 * 85675.
 * Swap the first digit 5 with the digit 7, this results in the number 87655.
 * Note that there may be other sequences of swaps but it can be shown that
 * 87655 is the largest possible number.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 10^9
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

vector<int> storeDigits(int num)
{
    vector<int> ans;
    
    while(num)
    {
        ans.push_back(num % 10);
        num /= 10;
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}

bool compare(int a,int b)
{
    if((a % 2) ^ (b % 2) == 0)
    {
        return a > b;
    }
    
    return false;
}

int convertToNumber(vector<int> nums)
{
    int ans = 0;
    
    for(int i=0;i<nums.size();i++)
    {
        ans = ans*10 + nums[i];
    }
    
    return ans;
}

class Solution {
public:
    int largestInteger(int num) {
        vector<int> nums = storeDigits(num);
        vector<int> oddIndexes, evenIndexes, odd, even;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] % 2)
            {
                oddIndexes.push_back(i);
                odd.push_back(nums[i]);
            }
            else
            {
                evenIndexes.push_back(i);
                even.push_back(nums[i]);
            }
        }
        
        sort(odd.begin(),odd.end(),greater<int> ());
        sort(even.begin(),even.end(),greater<int> ());
        
        for(int i=0;i<oddIndexes.size();i++)
        {
            nums[oddIndexes[i]] = odd[i];
        }
        
        for(int i=0;i<evenIndexes.size();i++)
        {
            nums[evenIndexes[i]] = even[i];
        }
        
        return convertToNumber(nums);
    }
};
// @lc code=end

