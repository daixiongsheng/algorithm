/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> v;
        for (int i = 0; i < numbers.size(); i++) {
            int reset = target - numbers[i];
            if (reset < numbers[i]) {
                continue;
            }
            int index = binarySearch(numbers, i + 1, numbers.size() - 1, reset);
            if (index != -1) {
                v.push_back(i + 1);
                v.push_back(index + 1);
                return v;
            }
        }
        return {};
    }

    int binarySearch(vector<int> &numbers, int l, int h, int v) {
        int mid;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (numbers[mid] == v) {
                return mid;
            }
            if (numbers[mid] < v) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
