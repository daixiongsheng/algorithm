/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode *root) {
        auto r = levelOrderBottom(root);
        vector<int> v;
        for (auto &i : r) {
            v.insert(v.begin(), i.top());
        }
        return v;
    }

    vector<priority_queue<int>> levelOrderBottom(TreeNode *root) {
        vector<priority_queue<int>> v;
        if (!root)
            return v;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size()) {
            // vector<int> vv;
            TreeNode *node = q.front();
            priority_queue<int> pq;
            int n = q.size();
            int i = 0;
            while (i++ < n) {
                TreeNode *node = q.front();
                pq.push(node->val);
                // vv.push_back(node->val);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            v.insert(v.begin(), pq);
        }
        return v;
    }
};
// @lc code=end
