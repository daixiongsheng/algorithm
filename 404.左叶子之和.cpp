/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
  private:
    int v;

  public:
    int sumOfLeftLeaves(TreeNode *root) {
        preorderTraversal(root, false);
        return v;
    }

    void preorderTraversal(TreeNode *root, bool l = true) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            if (l) {
                v += root->val;
            }
        }
        preorderTraversal(root->left);
        preorderTraversal(root->right, false);
    }
};
// @lc code=end
