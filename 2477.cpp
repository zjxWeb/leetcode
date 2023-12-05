/**
 * @file 2477.cpp 到达首都的最少油耗
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * @cite https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/description/
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>>dp(n+1);
        for(auto &e : roads){
            dp[e[0]].push_back(e[1]);
            dp[e[1]].push_back(e[0]);
        }
        long long res = 0;
        function<int(int,int)>dfs = [&](int cur,int fuel) -> int{
            int sum = 1;
            for(auto &e : dp[cur]){
               if(e != fuel){
                   int cnt = dfs(e,cur);
                   sum += cnt; 
                   res += (cnt + seats -1)/seats;
               }
            }
            return sum;
        };
        dfs(0,-1);
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> roads = {{0,1},
                                {1,2},  
                                {0,3}};
    int seats = 3;
    cout << s.minimumFuelCost(roads, seats) << endl;
    return 0;
}