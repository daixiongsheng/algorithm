/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
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
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	var result = [][]int{}
	var queue []*TreeNode
	var line = []*TreeNode{root}
	for len(line) > 0 {
		var ret []int
		for len(line) > 0 {
			node := line[0]
			ret = append(ret, node.Val)
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
			line = line[1:]
		}
		line = queue
		queue = nil
		result = append(result, ret)
	}
	return result
}
// @lc code=end

