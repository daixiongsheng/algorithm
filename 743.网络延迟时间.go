/*
 * @lc app=leetcode.cn id=743 lang=golang
 *
 * [743] 网络延迟时间
 */

// @lc code=start

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func networkDelayTime(times [][]int, n int, k int) int {
	var cost = make([][]int, n)
	var visited []bool
	for i := 0; i < n; i++ {
		cost[i] = make([]int, n)
		for j := 0; j < n; j++ {
			cost[i][j] = -1
		}
		cost[i][i] = 0
		visited = append(visited, false)
	}

	for _, node := range times {
		ui, vi, wi := node[0], node[1], node[2]
		cost[ui-1][vi-1] = wi
	}
	sum := 0
	for i := 0; i < n; i++ {
		f := a2b(k-1, i, n, cost, visited)
		if f == -1 {
			return f
		}
		sum = max(sum, f)
	}
	return sum
}

func a2b(from, to, n int, cost [][]int, visited []bool) int {
	m := 1<<31 - 1
	if cost[from][to] != -1 {
		m = cost[from][to]
	}
	visited[from] = true
	for i := 0; i < n; i++ {
		if i != to && i != from && cost[from][i] != -1 && !visited[i] {
			visited[i] = true
			f := a2b(i, to, n, cost, visited)
			visited[i] = false
			if f != -1 {
				m = min(m, f+cost[from][i])
			}
		}
	}
	visited[from] = false
	if m != 1<<31-1 {
		return m
	}
	return -1
}

// @lc code=end

