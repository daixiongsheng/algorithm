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
    vector<vector<Node *>> zigzagLevelOrder(Node *root) {
        if (!root)
            return {};
        vector<vector<Node *>> v;
        queue<Node *> q;
        q.push(root);
        while (q.size()) {
            vector<Node *> vv;
            vector<Node *> vvv;
            while (q.size()) {
                Node *node = q.front();
                q.pop();
                vv.push_back(node);
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

    Node *connect2(Node *root) {
        auto r = zigzagLevelOrder(root);
        for (auto &line : r) {
            for (size_t i = 0; i < line.size() - 1; i++) {
                line[i]->next = line[i + 1];
            }
        }
        return root;
    }

};
// @lc code=end
