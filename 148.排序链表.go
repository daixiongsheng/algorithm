/*
 * @lc app=leetcode.cn id=148 lang=golang
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */


 func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	l := 0
	temp := head
	for temp != nil {
		l++
		temp = temp.Next
	}
	temp = &ListNode{-1, head}
	for subL := 1; subL < l; subL++ {
		pre, cur := temp, temp.Next
		for cur != nil {
			head1 := cur
			for i := 0; i < subL; i++ {
				cur = cur.Next
			}
			head2 := cur.Next
			cur.Next = nil
			cur = head2

			for i := 0; i < subL && cur != nil && cur.Next != nil; i++ {
				cur = cur.Next
			}
			var next *ListNode
			if cur != nil {
				next = cur.Next
				cur.Next = nil
			}
			cur = next
			pre.Next = merge(head1, head2)
		}
	}
	return temp.Next
}
func merge(a1 *ListNode, a2 *ListNode) *ListNode {
	t1, t2 := a1, a2
	head := &ListNode{}
	ret := head
	for t1 != nil && t2 != nil {
		if t1.Val > t2.Val {
			head.Next = t2
			head = head.Next
			t2 = t2.Next
		} else {
			head.Next = t1
			head = head.Next
			t1 = t1.Next
		}
	}
	if t1 != nil {
		head.Next = t1
	}
	if t2 != nil {
		head.Next = t2
	}
	return ret.Next
}
// @lc code=end

