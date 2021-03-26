/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;

//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return head;
        auto r = new Node(head->val);
        map<Node *, Node *> m2;
        m2[head] = r;
        Node *p = head;
        Node *q = r;
        if (head->random) {
            if (head->random == head) {
                r->random = r;
            }
            else {
                r->random = new Node(head->random->val);
            }
            m2[head->random] = r->random;
        }

        while (p) {
            if (p->next) {
                if(m2[p->next]) {
                    q->next = m2[p->next];
                }
                else {
                    q->next = new Node(p->next->val);
                    m2[p->next] = q->next;
                }
            }
            if (p->random) {
                if (m2[p->random]) {
                    q->random = m2[p->random];
                } else if (p->random == p) {
                    q->random = q->random;
                } else {
                    q->random = new Node(p->random->val);
                    m2[p->random] = q->random;
                }
            }
            p = p->next;
            q = q->next;
        }
        return r;
    }
};
// @lc code=end
