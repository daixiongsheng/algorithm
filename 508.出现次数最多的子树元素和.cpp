/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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

#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
#include "vector"

using namespace std;
class Solution {
    int max = 1;
    map<int, int> m;

  public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        order(root);
        vector<int> v;
        for (auto &i : m) {
            if (i.second == max) {
                v.push_back(i.first);
            }
        }
        return v;
    }

    void order(TreeNode *root) {
        if (!root)
            return;
        int sum = traversal(root);
        if (m.count(sum)) {
            m[sum]++;
            max = max > m[sum] ? max : m[sum];
        } else {
            m[sum] = 1;
        }
        order(root->left);
        order(root->right);
    }
    int traversal(TreeNode *root) {
        if (!root)
            return 0;
        return root->val + traversal(root->left) + traversal(root->right);
    }
};
// @lc code=end
