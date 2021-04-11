/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sum = 0;

  public:
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        add(root, to_string(0));
        return sum;
    }

    void add(TreeNode *root, string v) {
        if (!root->left && !root->right) {
            v += to_string(root->val);
            sum += atoi(v.c_str());
        }
        string r = v + to_string(root->val);
        if (root->left)
            add(root->left, r);
        if (root->right)
            add(root->right, r);
    }
};
// @lc code=end
