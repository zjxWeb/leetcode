/**
 * @file 1631.cpp 最小体力消耗路径
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-11
 * @cite https://leetcode.cn/problems/path-with-midimum-effort/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 //constexpr 关键字的功能是使指定的常量表达式获得在程序编译阶段计算出结果的能力，而不必等到程序运行阶段。
//C++ 11 标准中，constexpr 可用于修饰普通变量、函数（包括模板函数）以及类的构造函数。
// 定义 移动的四个方向
static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // BFS + 二分查找
        int m = heights.size();
        int n = heights[0].size();
        int l = 0,r = 999999,res = 0;
        while(l <= r){
            // 二分法
            int mid = (l+r)>>1;
            queue<pair<int,int>> q;
            q.push({0,0});
            vector<int> seen (m * n);
            seen[0] = 1;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                // 搜寻四个方向
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];
                    // 判断边界
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && abs(heights[x][y] - heights[nx][ny]) <= mid){
                        q.push({nx,ny}); 
                        seen[nx * n + ny] = 1;  
                    }
                        
                }
            }
             if(seen[m * n - 1]){
                res = mid;
                r = mid -1;
            }
            else l = mid + 1;
            }
            return res;
        }
};

int main(){
    Solution s;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout << s.midimumEffortPath(heights) << endl;
}