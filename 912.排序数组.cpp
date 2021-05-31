/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "map"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void sort(vector<int> &nums, int l, int h) {
        if (l >= h) {
            return;
        }
        int i = l, j = h;
        int pos = l + ((h - l) >> 1);
        int value = nums[pos];
        swap(nums, l, pos);
        while (i < j) {
            while (value < nums[j] && i < j) j--;
            if (i < j)
                nums[i++] = nums[j];
            while (value > nums[i] && i < j) i++;
            if (i < j)
                nums[j--] = nums[i];
        }
        nums[i] = value;
        sort(nums, l, i - 1);
        sort(nums, i + 1, h);
    }

    inline void swap(vector<int> &nums, int l, int h) {
        int t = nums[h];
        nums[h] = nums[l];
        nums[l] = t;
    }

    void quickSort(vector<int> &num, int left, int right) {
        if (left >= right) {
            return;
        }
        int key = num[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (num[j] >= key && i < j) {
                j--;
            }
            while (num[i] <= key && i < j) {
                i++;
            }
            if (i < j) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
        num[left] = num[i];
        num[i] = key;
        quickSort(num, left, i - 1);
        quickSort(num, i + 1, right);
    }
};
// @lc code=end

