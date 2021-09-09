/*
 * @lc app=leetcode.cn id=236 lang=golang
 *
 * [236] 二叉树的最近公共祖先
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

 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil || root == p || root == q {
		return root
	}
	lChild := lowestCommonAncestor(root.Left, p, q)
	rChild := lowestCommonAncestor(root.Right, p, q)
	if rChild != nil && lChild != nil {
		return root
	}
	if lChild != nil {
		return lChild
	}
	if rChild != nil {
		return rChild
	}
	return nil
}
// @lc code=end

