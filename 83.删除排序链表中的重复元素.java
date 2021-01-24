/*
 * @lc app=leetcode.cn id=83 lang=java
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
// Definition for singly-linked list.
// public class ListNode {
//     int val;
//     ListNode next;
//     ListNode() {}
//     ListNode(int val) { this.val = val; }
//     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// }

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        head.next = deleteDuplicates(head.next);
        if(head.val == head.next.val) head = head.next;
        return head;
        // if(head==null){
        //     return null;
        // }
        // Set<Integer> set=new HashSet<Integer>();
        // set.add(head.val);
        // ListNode q=head;
        // ListNode p=head.next;
        // while(p!=null){
        //     if(set.contains(p.val)){
        //         p=p.next;
        //         q.next=p;
        //     }else{
        //         set.add(p.val);
        //         q=q.next;
        //         p=p.next;
        //     }
        // }
        // return head;
    }
}
// @lc code=end

