/*
 * @lc app=leetcode.cn id=1744 lang=c
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* canEat(int* candiesCount, int candiesCountSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    bool *answer;
    answer = (bool *)malloc(queriesSize * sizeof(bool *));
    *returnSize = queriesSize;
    long long i = 1;
    long long sum[candiesCountSize];
    sum[0] = candiesCount[0];
    long long lcp = candiesCountSize;
    long long l = queriesSize;
    for (int i = 1; i < lcp; ++i) {
        sum[i] = sum[i - 1] + candiesCount[i];
    }
    i = 0;
    for (;i < l; ++i) {
        long long tp = queries[i][0];
        long long day = queries[i][1];
        long long capp = queries[i][2];
        if (tp == 0) {
            answer[i] = day < sum[tp];
            continue;
        }
        if (day >= sum[tp] ||
            (day + 1)* capp <= sum[tp] - (sum[tp] - sum[tp -1]))  {
            answer[i] = false;
        } else {
            answer[i] = true;
        }
    }
    return answer;
}
// @lc code=end

