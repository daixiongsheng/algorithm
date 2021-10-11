/*
 * @lc app=leetcode.cn id=232 lang=golang
 *
 * [232] 用栈实现队列
 */

// @lc code=start

type MyQueue struct {
	data []int
	top  int
}

func Constructor() MyQueue {
	d := MyQueue{
		make([]int, 20),
		-1,
	}
	return d
}

func (this *MyQueue) Push(x int) {
	this.top++
	if this.top >= 20 {
		this.data = append(this.data, make([]int, 20)...)
	}
	this.data[this.top] = x
}

func (this *MyQueue) Pop() int {
	r := this.data[0]
	this.data = this.data[1:]
	this.top--
	return r
}

func (this *MyQueue) Peek() int {
	return this.data[0]
}

func (this *MyQueue) Empty() bool {
	return this.top == -1
}
/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
// @lc code=end

