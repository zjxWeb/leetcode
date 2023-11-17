/**
 * @file 48.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-17
 * 
 * @copyright Copyright (c) 2023
 * 旋转图像
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像
 * 
 * 示例一：
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
    输出：[[7,4,1],[8,5,2],[9,6,3]]

    示例 2：
    输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

    提示：

    n == matrix.length == matrix[i].length
    1 <= n <= 20
    -1000 <= matrix[i][j] <= 1000
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 将 A 沿着水平中线翻转，得到矩阵 A′。
        // 将 A′ 沿着主对角线翻转，得到矩阵 B。
        
        // 1. 先将矩阵 A 沿着水平中线翻转
        int m = matrix.size();// 行数
        for(int i = 0; i < m / 2; i++){
            for(int j = 0; j < m; j++){
                swap(matrix[i][j],matrix[m - i - 1][j]);
            }
        }
        // 2. 沿着主对角线翻转
        for(int i = 0; i < m; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(matrix);
    return 0;
}