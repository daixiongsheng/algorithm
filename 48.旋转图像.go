/*
 * @lc app=leetcode.cn id=48 lang=golang
 *
 * [48] 旋转图像
 */

// @lc code=start
func rotate(matrix [][]int) [][]int {
	swap := func(matrix [][]int, row1, col1, row2, col2 int) {
		tp := matrix[row1][col1]
		matrix[row1][col1] = matrix[row2][col2]
		matrix[row2][col2] = tp
	}
	n := len(matrix)
	for i := 0; i < n/2; i++ {
		for j := 0; j < n; j++ {
			swap(matrix, i, j, n-i-1, j)
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			swap(matrix, i, j, j, i)
		}
	}
	return matrix
}
// @lc code=end

