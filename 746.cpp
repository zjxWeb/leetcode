/**
 * @file 746.cpp使用最小花费爬楼梯
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-17
 * @cite https://leetcode.cn/problems/min-cost-climbing-stairs/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
};

int main () {
    Solution s;
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int res = s.minCostClimbingStairs(cost);
    cout << res << endl;
    return 0;
}