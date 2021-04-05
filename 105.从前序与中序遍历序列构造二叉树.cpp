/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (!preorder.empty())
            return nullptr;
        auto root = new TreeNode(preorder[0]);
        auto ret = root;
        int i = 0, j = 0;
        while (true) {
            do {
                root->left = new TreeNode(inorder[j]);
                root = root->left;
            } while (preorder[i] != inorder[j++]);
            i++;
            root = ret;
            do {
                root->right = new TreeNode(inorder[j]);
                root = root->left;
            } while (preorder[i] != inorder[j]);
        }
    }
};
// @lc code=end
