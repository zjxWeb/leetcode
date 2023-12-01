/**
 * @file 994.cpp 994. 腐烂的橘子
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-30
 * @cite https://leetcode.cn/problems/rotting-oranges/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;    

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs 来解决
       int counts = 0,fresh = 0;
       queue<pair<int,int>> q;
       for (int i = 0; i < grid.size(); i++) {
           for (int j = 0; j < grid[0].size(); j++) {
               if (grid[i][j] == 1) fresh++;
               else if(grid[i][j] == 2) q.push({i, j});
           }
       }
       vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
       while(!q.empty()){
            int n = q.size();
            bool rot = false;
            for(int i = 0; i < n; i++){
                auto cur = q.front();
                q.pop();
                for (auto dir : dirs) {
                    int x = cur.first + dir.first, y = cur.second + dir.second;
                    if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                        rot = true;
                    }
                }
            }
            if(rot) counts++;
       }
       return fresh ? -1 : counts;
    }
};

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution s;
    cout << s.orangesRotting(grid) << endl;
    return 0;
}