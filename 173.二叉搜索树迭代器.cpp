/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
  private:
    vector<int> v;
    int i = 0;

  public:
    void preorderTraversal(TreeNode *root) {
        if (!root)
            return;
        preorderTraversal(root->left);
        v.push_back((root->val));
        preorderTraversal(root->right);
    }
    BSTIterator(TreeNode *root) { preorderTraversal(root); }

    int next() { return v[i++]; }

    bool hasNext() { return i < v.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
