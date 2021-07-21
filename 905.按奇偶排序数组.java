/*
 * @lc app=leetcode.cn id=905 lang=java
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int i = -1, k = -1;
        while (++i < nums.length) {
            //  奇数，放后面
            if (nums[i] % 2 == 1) {
                k = i;
                while (++k < nums.length && nums[k] % 2 == 1 ) ;
                if (k == nums.length) break;
                nums[i] = nums[i] ^ nums[k];
                nums[k] = nums[i] ^ nums[k];
                nums[i] = nums[i] ^ nums[k];
            }
        }
        return nums;
    }
}
// @lc code=end

