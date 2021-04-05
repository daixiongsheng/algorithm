/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return root->val == targetSum;

        int n = targetSum - root->val;
        if (root->right) {
            bool b = hasPathSum(root->right, n);
            if (b)
                return b;
        }
        if (root->left) {
            bool b = hasPathSum(root->left, n);
            if (b)
                return b;
        }
        return false;
    }
};
// @lc code=end
