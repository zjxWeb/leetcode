/**
 * @file 2008.cpp 出租车的最大盈利
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * @cite https://leetcode.cn/problems/maximum-earnings-from-taxi/
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // 记忆化搜索
        vector<vector<pair<int,int>>>group(n+1);
        for (auto & el : rides){
            int start = el[0];
            int end = el[1];
            int tips = el[2];
            group[end].emplace_back(start,end - start + tips);
        }
        // 使用 -1 表示没有计算过
        vector<long long>dp(n+1, -1);
        function<long long (int)> dfs = [&](int i) -> long long {
            if(i == 1) return 0;
            auto & res = dp[i];
            if(res != -1) return res; // 已经记录
            res = dfs(i-1);
            for(auto &[s,t] : group[i]) res = max(res,dfs(s) + t);
            return res;
        };
        return dfs(n);
    }
};

int main() {
    Solution s;
    vector<vector<int>> rides = {{1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1}};
    cout << s.maxTaxiEarnings(20, rides) << endl;
    return 0;
}