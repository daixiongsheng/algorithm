/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层序遍历
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

func reverse(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
    s[i], s[j] = s[j], s[i]
	}
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	var result = [][]int{}
	var queue []*TreeNode
	var line = []*TreeNode{root}
	var b = true
	for len(line) > 0 {
		var ret []int
		for len(line) > 0 {
			node := line[0]
			ret = append(ret, node.Val)
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			line = line[1:]
		}
		line = queue
		queue = nil
		if b {
			reverse(ret)
			result = append(result, ret)
		} else {
			result = append(result, ret)
		}
		b = !b
	}
	return result
}
// @lc code=end

