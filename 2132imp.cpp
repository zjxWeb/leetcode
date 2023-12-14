/**
 * @file 2132.cpp 用邮票贴满网格图
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * @cite https://leetcode.cn/problems/stamping-the-grid/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        // 先计算前缀和
        int n = grid.size(),m = grid[0].size();
        // 定义前缀和数组
        vector<vector<int>> sum(n+1,vector<int>(m+1));
        for (int i = 0; i < n; i++){
            for(int j = 0;j < m;j++){
                sum[i+1][j+1] = sum[i+1][j]+sum[i][j+1]-sum[i][j]+grid[i][j];
            }
        }
        // 差分数组
        // 为方便第 3 步的计算，在 d 数组的最上面和最左边各加了一行（列），所以下标要 +1
        vector<vector<int>> d(n+2,vector<int>(m+2));
        for(int i = stampHeight;i < n+1;i++){
            for(int j = stampWidth;j < m+1;j++){
                int h = i - stampHeight + 1;
                int w = j - stampWidth + 1;
                // 判断子矩阵能不能放邮票
                if(sum[i][j] - sum[i][w-1] - sum[h-1][j] + sum[h-1][w-1] == 0){
                    d[h][w]++;
                    d[h][j+1]--;
                    d[i+1][w]--;
                    d[i+1][j+1]++;
                }
            }
        }
        // 还原差分矩阵
        for(int i = 0;i < n;i++){
            for(int j = 0; j < m;j++){
                d[i+1][j+1] += d[i+1][j] + d[i][j+1] - d[i][j];
                if(grid[i][j] == 0 && d[i+1][j+1] == 0) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>>grid = {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
    int stampHeight = 4, stampWidth = 3;
    cout << s.possibleToStamp(grid, stampHeight, stampWidth) << endl;
    return 0;
}