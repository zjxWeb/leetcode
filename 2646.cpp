/**
 * @file 2646.cpp 最小化旅行的价格总和
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-06
 * @cite https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
        vector<vector<int>> next(n);
        for (auto &edge : edges) {
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }

        vector<int> count(n);
        function<bool(int, int, int)> dfs = [&](int node, int parent, int end) -> bool {
            if (node == end) {
                count[node]++;
                return true;
            }
            for (int child : next[node]) {
                if (child == parent) {
                    continue;
                }
                if (dfs(child, node, end)) {
                    count[node]++;
                    return true;
                }
            }
            return false;
        };
        for (auto &trip: trips) {
            dfs(trip[0], -1, trip[1]);
        }

        function<pair<int, int>(int, int)> dp = [&](int node, int parent) -> pair<int, int> {
            pair<int, int> res = {
                price[node] * count[node], price[node] * count[node] / 2
            };
            for (int child : next[node]) {
                if (child == parent) {
                    continue;
                }
                auto [x, y] = dp(child, node);
                res.first += min(x, y); // node 没有减半，因此可以取子树的两种情况的最小值
                res.second += x; // node 减半，只能取子树没有减半的情况
            }
            return res;
        };
        auto [x, y] = dp(0, -1);
        return min(x, y);
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {{0,1},{1,2},{1,3}};
    vector<int> price = {2,2,10,6};
    vector<vector<int>> trips = {{0,3},{2,1},{2,3}};
    Solution s;
    cout << s.minimumTotalPrice(4, edges, price, trips) << endl;
    return 0;
}