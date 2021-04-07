/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
#include "vector"

using namespace std;

class Solution {
  private:
    vector<vector<int>> result;

  public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> v;
        if (!root)
            return {};
        pathSum(root, targetSum, v);
        return result;
    }

    bool isLeaf(TreeNode *root) { return !root->left && !root->right; }

    bool pathSum(TreeNode *root, int targetSum, vector<int> &v) {
        if (isLeaf(root) && targetSum == root->val) {
            v.push_back(root->val);
            result.push_back(v);
            return true;
        }
        v.push_back(root->val);
        targetSum -= root->val;
        if (root->left && pathSum(root->left, targetSum, v)) {
            v.pop_back();
        }
        if (root->right && pathSum(root->right, targetSum, v)) {
            v.pop_back();
        }
        v.pop_back();
        return false;
    }
};
// @lc code=end
