/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
    // Node* connect(Node* root) {

    // }

    Node *connect(Node *root) {
        if (!root)
            return nullptr;
        Node *right = root;
        while (right) {
            right->next = NULL;
            right = right->right;
        }
        pre(root);
        return root;
    }

    void pre(Node *root) {
        if (!root)
            return;
        l2r(root);
        pre(root->left);
        pre(root->right);
    }
    Node * getRight(Node *head) {
            auto tp = head->right;
            while (!tp) {
                tp = head->left ;
                head = head->next;
            }
    }
    void l2r(Node *root) {
        auto right = getRight(root);
        if (root->right && root->left) {
            root->left->next = root->right;
        }
    }
};
// @lc code=end
