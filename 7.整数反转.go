/*
 * @lc app=leetcode.cn id=7 lang=golang
 *
 * [7] 整数反转
 */
// package main

import (
	"fmt"
	"math"
	"strconv"
)
// @lc code=start
func reverse(x int) int {
	na := x < 0
	var naa int = 1
	if na {
		naa = 2
	}
	l := len(strconv.FormatInt(int64(x), 10))
	var result int64 = 0
	var i int64 = int64(math.Pow(10, float64(l - naa )))
	var tp int
	for x != 0 {
		tp = x % 10
		result += int64(tp) * i
		i /= 10
		x /= 10
	}
	if result < (-1 << 31) {
		return 0
	} else if result > (1 << 31 - 1) {
		return 0
	} else {
		return int(result)
	}
}

// func main() {
// 	fmt.Println(reverse(-123))
// }
// @lc code=end

