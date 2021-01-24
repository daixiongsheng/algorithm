/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
#include "iostream"
#include "queue"

using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> v;
        if(!root) return v;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()) {
            vector<int> vv;
            TreeNode *node = q.front();
            int n = q.size();
            int i = 0;
            while(i++ < n) {
                TreeNode *node = q.front();
                vv.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            v.insert(v.begin(), vv);
        }
        return v;
    }
};
// @lc code=end
