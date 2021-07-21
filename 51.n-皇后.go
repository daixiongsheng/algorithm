/*
 * @lc app=leetcode.cn id=51 lang=golang
 *
 * [51] N 皇后
 */

// @lc code=start

func solveNQueens(n int) [][]string {
	var result []string = make([]string, n, n)
	var res [][]string = make([][]string, 0)
	for j := range result {
		result[j] = strings.Repeat(".", n)
	}
	res = backward(result, 0, res)
	return res
}
func backward(path []string, row int, res [][]string) [][]string {
	if row == len(path) {
		var a []string = make([]string, row)
		copy(a, path)
		res = append(res, a)
		return res
	}
	n:= len(path[row])
	for col := 0; col < n; col++ {
		if !isValid(path, row, col) {
			continue
		}
		//path[row][col] = "Q"
		tp := []byte(path[row])
		tp[col] = 'Q'
		path[row] = string(tp)
		res = backward(path, row + 1, res)
		//path[row][col] = "."
		tp = []byte(path[row])
		tp[col] = '.'
		path[row] = string(tp)
	}
	return res
}

func isValid(path []string, row int, col int) bool  {
	n := len(path)
	for i := 0; i < n; i++ {
		if path[i][col] == 'Q' {
			return false
		}
	}
	// for i := 0; i < col; i++ {
	// 	if path[col][i] == 'Q' {
	// 		return false
	// 	}
	// }
	for i, j:= row - 1, col + 1; i >= 0 && j < n; {
		if path[i][j] == 'Q' {
			return false
		}
		i--
		j++
	}
	for i,j := row - 1, col - 1; i >= 0 && j>= 0 ; {
		if path[i][j] == 'Q' {
			return false
		}
		i--
		j--
	}
	return true
}


// @lc code=end

