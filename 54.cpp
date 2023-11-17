/**
 * @file 54.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-17
 * 
 * @copyright Copyright (c) 2023
 * 螺旋矩阵
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 
提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> arr(n,vector<int>(m));
        vector<int> res;
        // 分别分为上，右，下，左
        int t = 0,b = n - 1,l = 0,r = m - 1;
        while(t <= b && l <= r){
            for(int i = l; i <= r; i++) res.push_back(matrix[t][i]);
            for(int i = t + 1; i <= b; i++) res.push_back(matrix[i][r]);
            if(t < b) for(int i = r - 1; i >= l; i--) res.push_back(matrix[b][i]);
            if(l < r) for(int i = b - 1; i > t; i--) res.push_back(matrix[i][l]);
            t++;
            b--;
            l++;
            r--;
        }
        return res;
    }
};
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    for(auto el : s.spiralOrder(matrix))
    {
        cout << el << " ";
    }
    return 0;
}
