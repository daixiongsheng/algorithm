/*
 * @lc app=leetcode.cn id=114 lang=golang
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	var f func(root *TreeNode) *TreeNode
	f = func(root *TreeNode) *TreeNode {
		if root == nil || root.Left == nil && root.Right == nil {
			return root
		}
		ret := f(root.Left)
		root.Left = nil
		if ret != nil {
			right := root.Right
			root.Right = ret
			for ret.Right != nil {
				ret = ret.Right
			}
			ret.Right = f(right)
		} else {
			root.Right = f(root.Right)
		}
		return root
	}
	f(root)
}
// @lc code=end

