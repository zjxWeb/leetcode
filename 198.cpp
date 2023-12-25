/**
 * @file 198.cpp  打家劫舍
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/house-robber/description/
 * @version 0.1
 * @date 2023-12-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <functional>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
      // 1. 递归搜索 + 保存计算结果 = 记忆化搜索
        vector<int>memo(n,-1);// -1表示没有计算
        // dfs
        function<int(int)> dfs = [&](int i) -> int{
           if(i < 0) return 0; // 边界条件  没有房子
           if(memo[i]!= -1) return memo[i]; // 之前计算过
           return memo[i] = max(nums[i] + dfs(i-2), dfs(i-1));
        };
        return dfs(n-1);
    // 2. 1:1 翻译成递推
        vector<int>f(n+2);
        for(int i = 0; i < n; i++) f[i+2] = max(f[i+ 1] , f[i] + nums[i]);
        return f[n+1];
    // 空间优化
    // f0表示上一个  f1表示上上一个
        int f0 = 0, f1 = 0;
        for(auto el : nums){
            int new_f = max(f1, f0 + el);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    auto res = s.rob(nums);
    cout << res << endl;
    return 0;
}