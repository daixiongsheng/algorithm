/*
 * @lc app=leetcode.cn id=199 lang=golang
 *
 * [199] 二叉树的右视图
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
func rightSideView(root *TreeNode) []int {
	var ret []int
	if root == nil {
		return nil
	}
	dep, q := 1, []*TreeNode{root}
	for len(q) > 0 {
		sz := len(q)
		for i := 0; i < sz; i++ {
			cur := q[i]
			if i == sz-1 {
				ret = append(ret, cur.Val)
			}
			if cur.Left != nil {
				q = append(q, cur.Left)
			}
			if cur.Right != nil {
				q = append(q, cur.Right)
			}
		}
		q = q[sz:]
		dep++
	}
	return ret
}
// @lc code=end

