/*
 * @lc app=leetcode.cn id=113 lang=golang
 *
 * [113] 路径总和 II
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
func pathSum(root *TreeNode, targetSum int) [][]int {
	if root == nil {
		return nil
	}
	var ret [][]int
	var path []int

	var fn func(root *TreeNode, targetSum int)
	fn = func(root *TreeNode, targetSum int) {
		if root == nil {
			return
		}
		defer func() { path = path[:len(path)-1] }()
		path = append(path, root.Val)
		if root.Left == nil && root.Right == nil && targetSum == root.Val {
			ret = append(ret, append([]int(nil), path...))
		}
		fn(root.Left, targetSum-root.Val)
		fn(root.Right, targetSum-root.Val)
	}
	fn(root, targetSum)
	return ret
}

// @lc code=end
