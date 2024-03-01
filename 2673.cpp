/**
 * @file 2673.cpp 2673. 使二叉树所有路径值相等的最小代价
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-28
 * https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/description/
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        for(int i = n / 2;i > 0;i--){
            res += abs(cost[i*2-1] - cost[i*2]);// 两个节点变成一样的 // cost[i*2-1]左儿子  cost[i*2] 右儿子
            cost[i-1] += max(cost[i*2-1] ,cost[i*2]);// 累加路径和
        }
        return res;
    }
};

int main(){
    Solution  s;
    int n = 7;
    vector<int> cost = {1,5,2,2,3,3,1};
    cout << s.minIncrements(n, cost) << endl;
    return 0;
}