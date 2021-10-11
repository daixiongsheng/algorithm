/*
 * @lc app=leetcode.cn id=228 lang=golang
 *
 * [228] 汇总区间
 */

// @lc code=start

func summaryRanges(nums []int) []string {
	size := len(nums)
	if size == 0 {
		return []string{}
	}
	if size == 1 {
		return []string{strconv.Itoa(nums[0])}
	}
	result := []string{}
	const e = "->"
	l := 0
	i, num := 0, 0
	for i, num = range nums {
		if num-nums[l] > i-l {
			if i-l == 1 {
				result = append(result, strconv.Itoa(nums[l]))
			} else {
				result = append(result, strconv.Itoa(nums[l])+e+strconv.Itoa(nums[i-1]))
			}
			l = i
		}
	}
	if l == size-1 {
		result = append(result, strconv.Itoa(nums[size-1]))
	} else if l < size-1 {
		result = append(result, strconv.Itoa(nums[l])+e+strconv.Itoa(nums[size-1]))
	}
	return result
}
// @lc code=end

