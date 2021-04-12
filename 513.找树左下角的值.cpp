/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode *root) {
        m = height(root);
        preorderTraversal(root);
        return v;
    }

  private:
    int v;
    int m = 0;
    bool b = true;
    int height(TreeNode *root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        return 1 + max(height(root->left), height(root->right));
    }
    void preorderTraversal(TreeNode *root, int h = 1) {
        if (!root || !b)
            return;
        if (!root->left && !root->right && h == m && b) {
            v = root->val;
            b = false;
            return;
        }
        preorderTraversal(root->left, h + 1);
        preorderTraversal(root->right, h + 1);
    }
};
// @lc code=end
