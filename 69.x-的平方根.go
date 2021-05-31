/*
 * @lc app=leetcode.cn id=69 lang=golang
 *
 * [69] x 的平方根
 */

//package main
//
//import (
//	"fmt"
//	"math"
//)
//
//func main()  {
//	fmt.Println(mySqrt(0))
//}
// @lc code=start
func mySqrt(x int) int {
	if x == 0 {
		return 0
	}
	if x == 1 {
		return 1
	}
	var result float64
	start := 0.0
	end := float64(x)
	for true {
		mid := start + ((end - start) / 2.0 )
		tp := mid * mid
		if math.Abs(tp - float64(x)) < 1e-5 {
			result = mid
			break
		} else if tp > float64(x) {
			end = mid
		} else {
			start = mid
		}
	}
	return int(result)
}
// @lc code=end

