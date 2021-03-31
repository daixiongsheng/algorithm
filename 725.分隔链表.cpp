/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> v;
        if (!root || !root->next) {
            v.push_back(root);
            while (--k > 0) {
                v.push_back(nullptr);
            }
            return v;
        }
        auto p = root;
        int n = length(root);
        int size = n / k;
        int reset = n % k;
        int r = k - n;
        cout<< n<<endl;
        cout<< size<<endl;
        cout<< reset<<endl;
        cout<< r<<endl;
        cout<< k<<endl;
        while (n-- && p) {
            auto right = cut(p, size + (reset >0 ? 1 : 0));
            reset--;
            v.push_back(p);
            p = right;
        }
        while (r-- > 0) {
            v.push_back(nullptr);
        }
        return v;
    }
    int length(ListNode *root) {
        int n = 0;
        while (root && ++n)
            root = root->next;
        return n;
    }
    ListNode *cut(ListNode *head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }

        if (!p)
            return nullptr;
        auto ret = p->next;
        p->next = nullptr;
        return ret;
    }
};
// @lc code=end
