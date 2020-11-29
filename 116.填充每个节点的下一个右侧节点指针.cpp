/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* right = root;
        while (right!=NULL) {
            right->next = NULL;
            right = right->right;
        }
        pre(root);
        return root;
    }

    void pre(Node* root) {
        if(root == NULL) return;
        l2r(root);
        pre(root->left);
        pre(root->right);
    }

    void l2r(Node* root) {
        if(root->right != NULL && root->left != NULL) {
            root->left->next = root->right;
        }
    }
};
// @lc code=end

