/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
#include "iostream"
#include "string"
#include "vector"

// using namespace std;
// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if (!root) {
            return v;
        }
        string r = to_string(root->val);
        if (isLeaf(root)) {
            v.push_back(r);
            return v;
        }
        treePath(root->left, r, v);
        treePath(root->right, r, v);
        return v;
    }

    bool isLeaf(TreeNode *root) {
        return root->left == nullptr && root->right == nullptr;
    }

    void treePath(TreeNode *root, string from, vector<string> &v) {
        if (!root) {
            return;
        }
        string r = from + "->" + to_string(root->val);

        if (root->left) {
            treePath(root-> left, r, v);
        }

        if (root->right) {
            treePath(root->right, r, v);
        }
        if (isLeaf(root)) {
            v.push_back(r);
        }
    }
};
// @lc code=end
