/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
#include "regex"
#include "vector"

using namespace std;
class Codec {
  private:
    string sep = "@";

  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root)
            return "";
        string t = sep + to_string(root->val) + sep;
        serialize(root->left);
        return serialize(root->left) + t + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (!data.length())
            return NULL;
        std::cmatch cm;
        std::regex e("@([[:d:]]+)@");
        std::regex_search(data.c_str(), cm, e, std::regex_constants::match_any);
        for (size_t i = 0; i < cm.size(); ++i) {
            cout << cm[i] << "\n";
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
