/**
 * @file 240.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 搜索二维矩阵 II
 * 
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
 

示例 1：


输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
示例 2：


输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
每行的所有元素从左到右升序排列
每列的所有元素从上到下升序排列
-109 <= target <= 109

 */

#include<iostream>
#include<vector>
    
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 暴力超时了
        // int n = matrix.size();
        // int m = matrix[0].size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (matrix[i][j] == target) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // 优化 二分查找
        for(auto & el : matrix){
            // 使用lower_bound 找到第一个大于等于target的元素
            auto it = lower_bound(el.begin(), el.end(), target);
            if(it != el.end() && *it == target){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 3;
    bool res = s.searchMatrix(matrix, target);
    cout << res << endl;
    return 0;
}
