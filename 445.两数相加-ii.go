/*
 * @lc app=leetcode.cn id=445 lang=golang
 *
 * [445] 两数相加 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var v1, v2 []int
	var ret = &ListNode{}
	for l1 != nil {
		v1 = append(v1, l1.Val)
		l1 = l1.Next
	}
	for l2 != nil {
		v2 = append(v2, l2.Val)
		l2 = l2.Next
	}
	n1, n2, i, j := len(v1)-1, len(v2)-1, 0, 0
	carry := 0
	for i, j = n1, n2; i >= 0 && j >= 0; {
		r := v1[i] + v2[j] + carry
		if r > 9 {
			carry = 1
		} else {
			carry = 0
		}
		ret.Val = r%10
		ret = &ListNode{Next: ret}
		i--
		j--
	}
	for j >= 0 {
		r := v2[j] + carry
		if r > 9 {
			carry = 1
		} else {
			carry = 0
		}
		ret.Val = r%10
		ret = &ListNode{Next: ret}
		j--
	}
	for i >= 0 {
		r := v1[i] + carry
		if r > 9 {
			carry = 1
		} else {
			carry = 0
		}
		ret.Val = r%10
		ret = &ListNode{Next: ret}
		i--
	}
	if carry == 1 {
		ret.Val = carry % 10
		ret = &ListNode{Next: ret}
	}
	return ret.Next
}
// @lc code=end

