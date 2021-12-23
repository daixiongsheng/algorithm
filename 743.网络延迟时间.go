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
	inf := 1<<31 - 1
	var dist []int
	for i := 0; i < n; i++ {
		cost[i] = make([]int, n)
		for j := 0; j < n; j++ {
			cost[i][j] = inf
		}
		cost[i][i] = 0
		dist = append(dist, inf)
	}

	for _, node := range times {
		ui, vi, wi := node[0], node[1], node[2]
		cost[ui-1][vi-1] = wi
	}
	dist[k-1] = 0
	visited := make([]bool, n)
	for i := 0; i < n; i++ {
		m := -1
		for j := 0; j < n; j++ {
			if !visited[j] && (m==-1||(j != i && dist[j] < dist[m])) {
				m = j
			}
		}
		visited[m] = true
		for idx, v := range cost[m] {
			dist[idx] = min(dist[idx], dist[m]+v)
		}
	}
	var ret int
	for _, d := range dist {
		if d == inf {
			return -1
		}
		ret = max(ret, d)
	}
	return ret
}


// @lc code=end

