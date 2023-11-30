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
#include

using namespace std;    

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs 来解决
       
    }
};

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution s;
    cout << s.orangesRotting(grid) << endl;
    return 0;
}