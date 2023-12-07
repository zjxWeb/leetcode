/**
 * @file 1466. 重新规划路线
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-07
 * @cite https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //用 111 标记原方向的边，使用 000 标记反向边
        vector<vector<pair<int, int>>> edges(n);
        // 反方向的边
        for (auto el : connections) {
            edges[el[0]].push_back(make_pair(el[1], 1));
            edges[el[1]].push_back(make_pair(el[0], 0));
        }
        function<int(int, int)> dfs = [&](int a, int fa) {
            int ans = 0;
            for (auto& [b, c] : edges[a]) {
                if (b != fa) {
                    ans += c + dfs(b, a);
                }
            }
            return ans;
        };
        return dfs(0, -1);
    }
};

int main() {
    Solution s;
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << s.minReorder(6, connections) << endl;
    return 0;
}
