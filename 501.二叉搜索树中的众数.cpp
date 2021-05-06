/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int max = 1;
    int cur = 1;
    map<int, int> m;

  public:
    vector<int> findMode(TreeNode *root) {
        vector<int> v;
        traversal(root);
        for (auto &i : m) {
            if (i.second == max) {
                v.push_back(i.first);
            }
        }
        return v;
    }

    void traversal(TreeNode *root) {
        if (!root)
            return;
        traversal(root->left);
        if (m.count(root->val)) {
            m[root->val]++;
            max = max > m[root->val] ? max : m[root->val];
        } else {
            m[root->val] = 1;
        }
        traversal(root->right);
    }
};
// @lc code=end
