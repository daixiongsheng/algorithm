/*
 * @lc app=leetcode.cn id=435 lang=golang
 *
 * [435] 无重叠区间
 */

// @lc code=start

type Interval [][]int

func (a Interval) Len() int           { return len(a) }
func (a Interval) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a Interval) Less(i, j int) bool { return a[i][1] < a[j][1] }

func eraseOverlapIntervals(intervals [][]int) int {
	s := Interval(intervals)
	sort.Sort(s)
	var x_end = s[0][1]
	count := 1
	for _, v := range s {
		if v[0] >= x_end {
			count++
			x_end = v[1]
		}
	}
	return len(s) - count
}

// @lc code=end
