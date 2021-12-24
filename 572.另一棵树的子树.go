/*
 * @lc app=leetcode.cn id=572 lang=golang
 *
 * [572] 另一棵树的子树
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
func isSametree(s, t *TreeNode) bool {
	if s == nil && t == nil {
		return true
	}
	return s != nil &&
		t != nil &&
		s.Val == t.Val &&
		isSametree(s.Left, t.Left) &&
		isSametree(s.Right, t.Right)
}

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	if root == nil && subRoot == nil {
		return true
	}
	if root == nil && subRoot != nil {
		return false
	}
	if root != nil && subRoot == nil {
		return false
	}
	return isSametree(root, subRoot) ||
		isSubtree(root.Left, subRoot) ||
		isSubtree(root.Right, subRoot)
}

// @lc code=end

