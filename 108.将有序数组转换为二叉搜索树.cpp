/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return insert(nums, 0, nums.size() - 1);
    }
    TreeNode *insert(vector<int> &nums, int l, int h) {
        if (h < l) return nullptr;
        int mid = l + (h - l)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = insert(nums, l, mid - 1);
        root->right = insert(nums, mid + 1, h);
        return root;
    }
};
// @lc code=end
