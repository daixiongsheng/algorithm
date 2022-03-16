/*
 * @lc app=leetcode.cn id=1744 lang=golang
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// package main

// func main()  {
// 	// [7,4,5,3,8]
// 	// [[0,2,2],[4,2,4],[2,13,1000000000]]
// 	c := []int{46,5,47,48,43,34,15,26,11,25,41,47,15,25,16,50,32,42,32,21,36,34,50,45,46,15,46,38,50,12,3,26,26,16,23,1,4,48,47,32,47,16,33,23,38,2,19,50,6,19,29,3,27,12,6,22,33,28,7,10,12,8,13,24,21,38,43,26,35,18,34,3,14,48,50,34,38,4,50,26,5,35,11,2,35,9,11,31,36,20,21,37,18,34,34,10,21,8,5}
// 	//q := [][]int{{12, 301, 3}}
// 	q := [][]int{{85, 54, 42}}
// 	canEat(c, q)
// }
// @lc code=start
func canEat(candiesCount []int, queries [][]int) []bool {
	var l = len(queries)
	var answer = make([]bool, l)
	var lcp = len(candiesCount)

	i := 0
	for i = 1; i < lcp; i++ {
		candiesCount[i] = candiesCount[i-1] + candiesCount[i]
	}
	i = 0
	for ; i < l; i++ {
		tp, day, capp := queries[i][0], queries[i][1], queries[i][2]
		if tp == 0 {
			answer[i] = day < candiesCount[tp]
			continue
		}
		if day >= candiesCount[tp] ||
			(day+1)*capp <= candiesCount[tp]-(candiesCount[tp]-candiesCount[tp-1]) {
			answer[i] = false
		} else {
			answer[i] = true
		}
	}

	return answer
}

// @lc code=end

