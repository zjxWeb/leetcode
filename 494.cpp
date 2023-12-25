/**
 * @file 494.cpp 目标和
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/target-sum/description/
 * @version 0.1
 * @date 2023-12-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //  递归搜索 + 保存计算结果 = 记忆化搜索
        
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    auto res = s.findTargetSumWays(nums, target);
    cout << res << endl;
    return 0;
}