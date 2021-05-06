/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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

#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
#include "vector"

using namespace std;
class Solution {
  private:
    int result = 0;

  public:
    int pathSum(TreeNode *root, int targetSum) {
        order(root, targetSum);
        return result;
    }

    void order(TreeNode *root, int targetSum) {
        if (!root)
            return;
        _pathSum(root, targetSum);
        if (root->left)
            order(root->left, targetSum);
        if (root->right)
            order(root->right, targetSum);
    }

    void _pathSum(TreeNode *root, int targetSum) {
        if (targetSum == root->val) {
            result++;
        }
        targetSum -= root->val;
        if (root->left) {
            _pathSum(root->left, targetSum);
        }
        if (root->right) {
            _pathSum(root->right, targetSum);
        }
    }
};
// @lc code=end

