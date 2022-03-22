/*
 * @lc app=leetcode.cn id=452 lang=golang
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
type Point [][]int

func (a Point) Len() int           { return len(a) }
func (a Point) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a Point) Less(i, j int) bool { return a[i][1] < a[j][1] }

func findMinArrowShots(points [][]int) int {
	s := Point(points)
	sort.Sort(s)
	var x_end = s[0][1]
	count := 1
	for _, v := range s {
		if v[0] > x_end {
			count++
			x_end = v[1]
		}
	}
	return count
}

// @lc code=end

