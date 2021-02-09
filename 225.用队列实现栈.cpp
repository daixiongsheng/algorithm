/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
private:
    int topIndex = -1;
    int arr[100];
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        arr[++topIndex] = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        return arr[topIndex--];
    }

    /** Get the top element. */
    int top() {
        return arr[topIndex];
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return topIndex == -1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

