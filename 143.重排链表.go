/*
 * @lc app=leetcode.cn id=143 lang=golang
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 func reverse(head *ListNode) *ListNode {
	cur, next := head, head.Next
	var pre *ListNode = nil
	for cur != nil {
		next = cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}

func merge(left, right *ListNode) {
	var pl, pr *ListNode
	for left != nil && right != nil {
		ln := left.Next
		rn := right.Next
		left.Next = right
		right.Next = ln
		pl = left
		pr = right
		right = rn
		left = ln
	}
	if right != nil {
		pr.Next = right
	}
	if left != nil {
		pl.Next = left
	}
}


// 快慢指针，先定位到中点， 再反转后面部分，再合并两个列表
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}
	slow, quick := head, head
	pre := quick
	for quick != nil && quick.Next != nil {
		pre = slow
		slow = slow.Next
		quick = quick.Next.Next
	}
	pre.Next = nil
	quick = reverse(slow)
	merge(head, quick)
}
// @lc code=end

