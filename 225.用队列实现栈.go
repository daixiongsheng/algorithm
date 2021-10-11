/*
 * @lc app=leetcode.cn id=225 lang=golang
 *
 * [225] 用队列实现栈
 */

// @lc code=start

type MyStack struct {
	data []int
	top int
}


func Constructor() MyStack {
	const n = 20
	s := MyStack{
		make([]int, n),
		-1,
	}
	return s
}


func (this *MyStack) Push(x int)  {
	this.top++
	if this.top >= 20 {
		this.data= append(this.data, make([]int, 20)...)
	}
	this.data[this.top] = x
}


func (this *MyStack) Pop() int {
	ret := this.data[this.top]
	this.top--
	return ret
}


func (this *MyStack) Top() int {
	return this.data[this.top]
}


func (this *MyStack) Empty() bool {
	return this.top == -1
}

/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */
// @lc code=end

