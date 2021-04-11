/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        preorderTraversal(v, root);
        return v;
    }

    void preorderTraversal(vector<int> &v, TreeNode *root) {
        if (!root)
            return;
        preorderTraversal(v, root->left);
        preorderTraversal(v, root->right);
        v.push_back((root->val));
    }
};
// @lc code=end
