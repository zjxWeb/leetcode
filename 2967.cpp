/**
 * @file 2967.cpp  使数组成为等数数组的最小代价
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-18
 * @cite https://leetcode.cn/problems/minimum-cost-to-make-array-equalindromic/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 枚举回文数，分为偶数和奇数
vector<int>pal;

auto init = [] {
    // 严格按顺序从小到大生成所有回文数
    for (int base = 1; base <= 10000; base *= 10) {
        // 奇数长度
        for (int i = base; i < base * 10; i++) {
            int x = i;
            for (int t = i / 10; t; t /= 10) {
                x = x * 10 + t % 10;
            }
            pal.push_back(x);
        }
        // 偶数长度
        if (base <= 1000) {
            for (int i = base; i < base * 10; i++) {
                int x = i;
                for (int t = i; t; t /= 10) {
                    x = x * 10 + t % 10;
                }
                pal.push_back(x);
            }
        }
    }
    pal.push_back(1'000'000'001); // 哨兵，防止下面代码中的 i 下标越界
    return 0;
}();

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        // 求总代价
        auto cost = [&](int i) -> long long{
            int target = pal[i];
            long long res = 0;
            for(int el : nums) res += abs(el - target);
            return res;
        };

        int n = nums.size();

        // 二分查找回文数
        int i = lower_bound(pal.begin(),pal.end(),nums[(n-1)/2]) - pal.begin();
        if(pal[i] <= nums[ n / 2 ]) return cost(i);
        return min(cost(i-1),cost(i));
    }
};

int main(){
    Solution s;
    vector<int> nums = {301,309,312,322};
    cout << s.minimumCost(nums) << endl;
    return 0;
}
