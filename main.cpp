#include "iostream"
#include <vector>
#include "21.merge-two-sorted-lists.cpp"

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(4);

    ListNode *q = new ListNode(1);
    q->next = new ListNode(3);
    q->next->next = new ListNode(4);
    ListNode *r = (new Solution())->mergeTwoLists(p, q);
    while (r) {
        std::cout << r->val << std::endl;
        r = r->next;
    }
    return 0;
}