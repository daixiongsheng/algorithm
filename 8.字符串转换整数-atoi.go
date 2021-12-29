/*
 * @lc app=leetcode.cn id=8 lang=golang
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

func myAtoi(s string) int {
	neg := int64(1)
	sum := int64(0)
	j := 0
	b := false
	for i := range s {
		if '0' <= s[i] && s[i] <= '9' {
			if sum == 0 && s[i] == '0' && i+1 < len(s) && !('0' <= s[i+1] && s[i+1] <= '9') {
				return 0
			}
			if s[i] == '0' && sum == 0 {
				continue
			}
			if j >= 11 {
				if neg == -1 {
					return -1 << 31
				}
				return 1<<31 - 1
			}
			j++
			sum = sum*10 + int64(s[i]-'0')
		} else if s[i] == ' ' {
			if sum != 0 {
				break
			}
			continue
		} else if s[i] == '-' {
			if b {
				break
			}
			if i+1 < len(s)-1 && !('0' <= s[i+1] && s[i+1] <= '9') {
				return 0
			}
			if sum != 0 {
				break
			}
			neg = -1
			b = true
		} else if s[i] == '+' {
			if b {
				break
			}
			if i+1 < len(s)-1 && !('0' <= s[i+1] && s[i+1] <= '9') {
				return 0
			}
			if sum != 0 {
				break
			}
			neg = 1
			b = true
		} else {
			break
		}
	}
	//-231, 231 - 1
	r := neg * sum
	if r < (-1 << 31) {
		return -1 << 31
	} else if r > 1<<31-1 {
		return 1<<31 - 1
	}
	return int(neg * sum)
}

// @lc code=end

