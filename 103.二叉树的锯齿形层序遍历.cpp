/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root)
            return {};
        vector<vector<int>> v;
        queue<TreeNode *> q;
        q.push(root);
        bool b = true;
        while (q.size()) {
            vector<int> vv;
            vector<TreeNode *> vvv;
            while (q.size()) {
                TreeNode *node = q.front();
                q.pop();
                vv.push_back(node->val);
                if (node->left) {
                    vvv.push_back(node->left);
                }
                if (node->right) {
                    vvv.push_back(node->right);
                }
            }
            for (auto &i : vvv) {
                q.push(i);
            }
            if (!b)
                reverse(vv.begin(), vv.end());
            v.push_back(vv);
            b = !b;
        }
        return v;
    }
};
// @lc code=end
