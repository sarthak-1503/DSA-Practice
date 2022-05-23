/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (57.86%)
 * Likes:    8499
 * Dislikes: 231
 * Total Accepted:    710.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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

    int idx ;

    Solution() {
        idx = 0;
    }

    TreeNode* newnode(int x)
    {
        TreeNode* t = new TreeNode(x);
        t -> val = x;
        t->left = NULL;
        t->right = NULL;

        return t;
    }

    TreeNode* build(vector<int> preorder,vector<int> inorder,int start,int end)
    {
        if(start > end)
        {
            return NULL;
        }


        TreeNode* root = newnode(preorder[idx++]);
        int pos = find(inorder.begin()+start,inorder.begin()+end+1,root->val) - inorder.begin();

        root->left = build(preorder,inorder,start,pos-1);
        root->right = build(preorder,inorder,pos+1,end);

        return root;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return build(preorder,inorder,0,inorder.size()-1);
    }
};
// @lc code=end

