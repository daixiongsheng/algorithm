/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    TreeNode *cur;

  public:
    void flatten(TreeNode *root) {
        if (!root)
            return;
        preorder(root);
    }

    TreeNode *preorder(TreeNode *root) {
        if (!root)
            return root;
        if (cur) {
            cur->left = nullptr;
            cur->right = root;
            cur = cur->right;
        } else {
            cur = root;
        }
        auto tp = cur->right;
        auto tp2 = cur->left;

        preorder(tp2);
        preorder(tp);
        return root;
    }
};
// @lc code=end
