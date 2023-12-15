/**
 * @file 74.cpp 搜索二维矩阵
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * @cite https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int n = matrix.size();
        // int m = matrix[0].size();
        // if(n == 0 ) return false;
        // // 使用二分法进行查找目标元素
        // for(int i = 0; i < n; i++){
        //     int l = 0;
        //     int r = m - 1;
        //     while(l <= r){
        //         int mid = (l + r) / 2;
        //         if(matrix[i][mid] == target) return true;
        //         else if(matrix[i][mid] > target) r = mid - 1;
        //         else l = mid + 1;
        //     }
        // }
        // return false;

        // 一次二分查找
        int n = matrix.size(),m = matrix[0].size();
        int l = 0,r = n * m - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int row = mid / m, col = mid % m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    Solution s;
    cout << s.searchMatrix(matrix, 3) << endl;
    return 0;
}