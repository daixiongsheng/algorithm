/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
  public:
    /** initialize your data structure here. */

    void push(int x) {
        this->arr[++this->topIndex] = x;
        this->minValue = this->minValue <= x ? this->minValue : x;
        this->minArr[this->topIndex] = this->minValue;
    }

    void pop() {
        this->minArr[this->topIndex] = 2147483647;
        this->topIndex--;
        if (this->topIndex >= 0)
            this->minValue = this->minArr[this->topIndex];
        else
            this->minValue = 2147483647;
    }

    int top() { return this->arr[this->topIndex]; }

    int getMin() { return this->minValue; }

  private:
    int topIndex = -1;
    int minValue = 2147483647;
    int arr[8000] = {0};
    int minArr[8000] = {0};
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
