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

#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
#include "vector"

using namespace std;
class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty())
            return nullptr;
        auto root_val = preorder[0];
        int i = 0;
        for (; i < inorder.size(); ++i) {
            if (inorder[i] == root_val) {
                i++;
                break;
            }
        }
        auto root = new TreeNode(preorder[0]);
        vector<int> v1(preorder.begin() + 1, preorder.begin() + i);
        vector<int> v2(inorder.begin(), inorder.begin() + i);
        vector<int> v3(preorder.begin() + i, preorder.end());
        vector<int> v4(inorder.begin() + i, inorder.end());
        root->left = buildTree(v1, v2);
        root->right = buildTree(v3, v4);
        return root;
    }
};
// @lc code=end
