/*
 * @lc app=leetcode.cn id=6 lang=golang
 *
 * [6] Z 字形变换
 */
/*
1234   N1 1234

1357   2 1357 2
2468     2468

1 5 9  3 1 5 9
246810   2468 10
3 7 11

1  7   4 1  7
2 68     2  68
35 9
4  10

1   9  5 1  9
2  810   2  8 10
3 7
46
5





*/
// @lc code=start
func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	N := len(s)
	for j := 1; j <= numRows; j++ {
		for i := 1; i < N; i += (numRows - j) * 2 {

		}
	}
}

// @lc code=end

