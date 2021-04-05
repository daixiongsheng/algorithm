/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root)
            return {};
        vector<vector<int>> v;
        queue<TreeNode *> q;
        q.push(root);
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
            v.push_back(vv);
            for(auto &i: vvv) {
                q.push(i);
            }
        }
        return v;
    }
};
// @lc code=end
