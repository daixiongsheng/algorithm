/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
#include "vector"

using namespace std;
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
    bool traversal(TreeNode *root, long long &v) {
        if (!root) {
            return true;
        }
        if (root->left) {
            bool r = traversal(root->left, v);
            if (!r)
                return r;
        }
        if (v >= root->val) {
            return false;
        }
        v = root->val;
        if (root->right) {
            return traversal(root->right, v);
        }
        return true;
    }
    bool isValidBST(TreeNode *root) {
        if (!root)
            return false;
        long long v = INT64_MIN;
        return traversal(root, v);
    }
};
// @lc code=end
