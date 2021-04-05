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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto v = zigzagLevelOrder(root);
        reverse(v.begin(), v.end());
        return v;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
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
            for (auto &i : vvv) {
                q.push(i);
            }
            v.push_back(vv);
        }
        return v;
    }
};
// @lc code=end

