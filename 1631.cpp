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
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * @brief 二分法
 * 
 */
// class Solution {
//  //constexpr 关键字的功能是使指定的常量表达式获得在程序编译阶段计算出结果的能力，而不必等到程序运行阶段。
// //C++ 11 标准中，constexpr 可用于修饰普通变量、函数（包括模板函数）以及类的构造函数。
// // 定义 移动的四个方向
// static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         // BFS + 二分查找
//         int m = heights.size();
//         int n = heights[0].size();
//         int l = 0,r = 999999,res = 0;
//         while(l <= r){
//             // 二分法
//             int mid = (l+r)>>1;
//             queue<pair<int,int>> q;
//             q.push({0,0});
//             vector<int> seen (m * n);
//             seen[0] = 1;
//             while(!q.empty()){
//                 auto [x,y] = q.front();
//                 q.pop();
//                 // 搜寻四个方向
//                 for (int i = 0; i < 4; i++)
//                 {
//                     int nx = x + dirs[i][0];
//                     int ny = y + dirs[i][1];
//                     // 判断边界
//                     if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && abs(heights[x][y] - heights[nx][ny]) <= mid){
//                         q.push({nx,ny}); 
//                         seen[nx * n + ny] = 1;  
//                     }
                        
//                 }
//             }
//              if(seen[m * n - 1]){
//                 res = mid;
//                 r = mid -1;
//             }
//             else l = mid + 1;
//             }
//             return res;
//         }
// };


/**
 * @brief 并查集
 * 
 */

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;
public:
    UnionFind(int n):n(n),setCount(n),parent(n),size(n,1){
        iota(parent.begin(),parent.end(),0);
    }
    // 定义查找函数
    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    // 定义合并函数
    bool unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(size[x] < size[y]) swap(x,y);
        parent[y] = x;
        size[x] += size[y];
        setCount--;
        return true;
    }

    // 判断是否连接
    bool connected(int x,int y){
        return find(x) == find(y);
    }
};
class Solution {
public:    
     int midimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (i > 0) {
                    edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
            auto&& [x1, y1, v1] = e1;
            auto&& [x2, y2, v2] = e2;
            return v1 < v2;
        });

        UnionFind uf(m * n);
        int ans = 0;
        for (const auto [x, y, v]: edges) {
            uf.unite(x, y);
            if (uf.connected(0, m * n - 1)) {
                ans = v;
                break;
            }
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout << s.midimumEffortPath(heights) << endl;
}