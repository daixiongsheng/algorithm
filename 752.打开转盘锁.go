/*
 * @lc app=leetcode.cn id=752 lang=golang
 *
 * [752] 打开转盘锁
 */

// @lc code=start

func include(strs []string, target string) bool {
	for _, s := range strs {
		if s == target {
			return true
		}
	}
	return false
}

func downString(str string, pos int) string {
	var b = []byte(str)
	if b[pos] == '0' {
		b[pos] = '9'
	} else {
		b[pos] -= 1
	}
	return string(b)
}

func upString(str string, pos int) string {
	var b = []byte(str)
	if b[pos] == '9' {
		b[pos] = '0'
	} else {
		b[pos] += 1
	}
	return string(b)
}


func openLock(deadends []string, target string) int {
	var visited []string
	for _, d := range deadends {
		visited = append(visited, d)
	}
	step := 0
	var q1 = []string{"0000"}
	var q2 = []string{target}
	for len(q1) > 0 && len(q2) > 0 {
		var tmp []string
		sz := len(q1)
		for i := 0; i < sz; i++ {
			cur := q1[i]
			if include(visited, cur) {
				continue
			}
			visited = append(visited, cur)
			if include(q2, cur) {
				return step
			}
			for j := 0; j < 4; j++ {
				s := downString(cur, j)
				if !include(visited, s) {
					tmp = append(tmp, s)
				}
				s = upString(cur, j)
				if !include(visited, s) {
					tmp = append(tmp, s)
				}
			}
		}
		q1 = q2
		q2 = tmp
		step++
	}
	return -1
}
// @lc code=end

