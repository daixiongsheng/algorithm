/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    int top = 0;
    int tail = 0;
    int arr[100];
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        arr[tail++] = x;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        return arr[top++];
    }

    /** Get the front element. */
    int peek() {
        return arr[top];
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return tail == top;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

