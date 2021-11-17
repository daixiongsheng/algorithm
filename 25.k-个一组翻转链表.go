/*
 * @lc app=leetcode.cn id=25 lang=golang
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var ret *ListNode
	var pre *ListNode

	for head != nil {
		i := k
		p := head
		for i > 1 && p != nil {
			p = p.Next
			i--
		}
		if p == nil {
			break
		}
		next := p.Next
		p.Next = nil
		tail := head
		head = reverse(head)
		if pre != nil {
			pre.Next = head
		}
		if ret == nil {
			ret = head
		}
		tail.Next = next
		pre = tail
		head = next
	}
	if ret == nil {
		ret = head
	}
	return ret
}

func reverse(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var (
		pre  *ListNode = nil
		next *ListNode = nil
		cur  *ListNode = nil
	)
	pre = head
	cur = head.Next
	pre.Next = nil
	for cur != nil {
		next = cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}
// @lc code=end

