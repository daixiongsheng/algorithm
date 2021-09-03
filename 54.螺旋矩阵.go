/*
 * @lc app=leetcode.cn id=54 lang=golang
 *
 * [54] 螺旋矩阵
 */

// @lc code=start


func spiralOrder(matrix [][]int) []int {
	size := len(matrix)*len(matrix[0])
	arr := make([]int, size)
	i := 0
	col, row := 0, 0
	w, h := len(matrix[0]), len(matrix)
	fmt.Println(len(arr))
	for col < w && row < h {
		c, r := col, row
		for ; c < w; c++ {
			arr[i] = matrix[r][c]
			i++
		}
		if i == size {
			break
		}

		r++
		c--


		for ; r < h; r++ {
			arr[i] = matrix[r][c]
			i++
		}
		if i == size {
			break
		}
		c--
		r--


		for ; c >= col; c-- {
			arr[i] = matrix[r][c]
			i++
		}
		if i == size {
			break
		}
		c++
		r--

		for ; r > row; r-- {
			arr[i] = matrix[r][c]
			i++
		}
		if i == size {
			break
		}
		row++
		w--
		h--
		col++
	}
	return arr
}

// @lc code=end

