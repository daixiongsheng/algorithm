/*
 * @lc app=leetcode.cn id=111 lang=golang
 *
 * [111] 二叉树的最小深度
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


func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	dep, q := 1, []*TreeNode{root}
	for len(q) > 0 {
		sz := len(q)
		for i := 0; i < sz; i++ {
			cur := q[i]
			if cur.Left == nil && cur.Right == nil {
				return dep
			}
			if cur.Left != nil {
				q = append(q, cur.Left)
			}
			if cur.Right != nil {
				q = append(q, cur.Right)
			}
		}
		q=q[sz:]
		dep++
	}
	return dep
}
// @lc code=end

