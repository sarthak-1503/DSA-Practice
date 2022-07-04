/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (37.15%)
 * Likes:    3688
 * Dislikes: 282
 * Total Accepted:    240.8K
 * Total Submissions: 623.5K
 * Testcase Example:  '[1,0,2]'
 *
 * There are n children standing in a line. Each child is assigned a rating
 * value given in the integer array ratings.
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * Return the minimum number of candies you need to have to distribute the
 * candies to the children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ratings = [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ratings = [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * The third child gets 1 candy because it satisfies the above two
 * conditions.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == ratings.length
 * 1 <= n <= 2 * 10^4
 * 0 <= ratings[i] <= 2 * 10^4
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> store(n,1);

        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                store[i] = store[i-1] + 1;
            }
        }

        for(int i=n-1;i>0;i--)
        {
            if(ratings[i-1] > ratings[i])
            {
                store[i-1] = max(store[i-1],store[i]+1);
            }
        }

        return accumulate(store.begin(),store.end(),0);
    }
};
// @lc code=end

