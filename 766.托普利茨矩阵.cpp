/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;
// @lc code=start
class Solution {
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int row = 0, col = 0;
        while (row < rowSize - 1 && col < colSize) {
            int curRpw = row, curCol = col;
            int c = matrix[curRpw][curCol];
            while (++curRpw < rowSize && ++curCol < colSize) {
                if (matrix[curRpw][curCol] != c) {
                    return false;
                }
            }
            col++;
        }
        col = 0;
        row = 1;
        while (row < rowSize && col < colSize - 1) {
            int curRpw = row, curCol = col;
            int c = matrix[curRpw][curCol];
            while (++curRpw < rowSize && ++curCol < colSize) {
                if (matrix[curRpw][curCol] != c) {
                    return false;
                }
            }
            row++;
        }
        return true;
    }
};
// @lc code=end
