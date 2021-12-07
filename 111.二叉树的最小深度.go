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
	var Min = func(a, b int) int {
		if a > b {
			return b
		}
		return a
	}
	var bfs func(root *TreeNode) int
	bfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		if root.Left == nil && root.Right == nil {
			return 1
		}
		if root.Left == nil {
			return 1 + bfs(root.Right)
		}
		if root.Right == nil {
			return 1 + bfs(root.Left)
		}
		return 1 + Min(bfs(root.Left), bfs(root.Right))
	}
	return bfs(root)
}
// @lc code=end

