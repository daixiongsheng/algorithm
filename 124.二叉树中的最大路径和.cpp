/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "map"

using namespace std;
class Solution {
    int max = 0;
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        if(isLeaf(root)) {
            return root->val;
        }
        maxSum(root);
        return max;
    }

    bool isLeaf(TreeNode *root) {
        return !root->left && !root->right;
    }

    int maxSum(TreeNode* root) {
        if(!root) return 0;
        if(isLeaf(root)) {
            return root->val;
        }
        int maxL = maxSum(root->left);
        int maxR = maxSum(root->right);
        max = root->val + std::max(std::max(maxR, 0), std::max(0, maxL));
        return root->val + std::max(maxR, maxL);
    }
};
// @lc code=end

