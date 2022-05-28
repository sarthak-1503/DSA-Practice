/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (62.95%)
 * Likes:    1521
 * Dislikes: 227
 * Total Accepted:    109K
 * Total Submissions: 173K
 * Testcase Example:  '[5,2,-3]'
 *
 * Given the root of a binary tree, return the most frequent subtree sum. If
 * there is a tie, return all the values with the highest frequency in any
 * order.
 * 
 * The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,2,-3]
 * Output: [2,-3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,2,-5]
 * Output: [2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int storeFreq(TreeNode* root, map<int,int> &m)
    {
        if(!root)
        {
            return 0;
        }

        root->val += storeFreq(root->left, m);
        root->val += storeFreq(root->right,m);

        m[root->val]++;
        return root->val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> m;
        
        int temp = storeFreq(root,m);
        int ma = INT_MIN;

        for(auto ptr : m)
        {
            ma = max(ma,ptr.second);
        }

        vector<int> ans;

        for(auto ptr : m)
        {
            if(ptr.second == ma)
            {
                ans.push_back(ptr.first);
            }
        }

        return ans;
    }
};
// @lc code=end

