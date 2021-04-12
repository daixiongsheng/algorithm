/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
  public:
    vector<int> rightSideView(TreeNode *root) {
        auto r = levelOrderBottom(root);
        vector<int> v;
        for (auto &i : r) {
            v.insert(v.begin(), i[i.size() - 1]);
        }
        return v;
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> v;
        if (!root)
            return v;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size()) {
            vector<int> vv;
            TreeNode *node = q.front();
            int n = q.size();
            int i = 0;
            while (i++ < n) {
                TreeNode *node = q.front();
                vv.push_back(node->val);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            v.insert(v.begin(), vv);
        }
        return v;
    }
};
// @lc code=end
