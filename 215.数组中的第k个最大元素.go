/*
 * @lc app=leetcode.cn id=215 lang=golang
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start


func findKthLargest(arr []int, k int) int {
	var heapify func(arr []int, index , size int)
	heapify = func(arr []int, index ,size int) {
		left, right:= index*2 + 1,index*2 + 2
		max := index
		if left < size && arr[left] > arr[index] {
			max = left
		}
		if right < size && arr[right] > arr[max] {
			max = right
		}
		// 找到左右子树中最大的一个进行交换
		if max != index {
			arr[index], arr[max] = arr[max], arr[index]
			heapify(arr, max, size)
		}
	}

	var buildHeap = func(arr []int) {
		size := len(arr)
		for i :=  size / 2; i >= 0; i-- {
			heapify(arr, i, size)
		}
	}
	size := len(arr)
	buildHeap(arr)
	for i := size - 1; i >= len(arr) - k + 1; i-- {
		arr[0], arr[i] = arr[i],arr[0]
		size--
		heapify(arr, 0, size)
	}
	return arr[0];
}
// @lc code=end

