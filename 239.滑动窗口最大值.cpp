/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <deque>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start

struct Window {

    Window() : data({}) {}
    deque<int> data;
    void push(int n);
    int max();
    void pop(int n);
};

int Window::max() { return data.front(); }

void Window::push(int n) {
    while (!data.empty() && data.back() < n) {
        data.pop_back();
    }
    data.push_back(n);
}

void Window::pop(int n) {
    if (!data.empty() && data.front() == n) {
        data.pop_front();
    }
}

class Solution {
  public:
    Window window;

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        if (nums.size() == 0)
            return res;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};
// @lc code=end

// int main() {
//     Solution s;
//     vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
//     auto r = s.maxSlidingWindow(v, 3);
//     for (auto i : r) {
//         cout << i << endl;
//     }
//     return 0;
// }
