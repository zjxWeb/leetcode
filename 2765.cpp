/**
 * @file 2765.cpp2765. 最长交替子数组
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-23
 * https://leetcode.cn/problems/longest-alternating-subarray/description/
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        int i = 0;
        while(i < n-1 ){
            if(nums[i+1] - nums[i] != 1){
                i++;
                continue;// 不满足条件直接跳过
            }
            int i0 = i;// 记录这一组的开始位置
            i+= 2;// i 和 i+1 已经满足要求，从 i+2 开始判断
            while(i < n && nums[i] == nums[i0] + (i - i0) % 2){
                i++;
            }
            //从 i0 到 i-1 是满足题目要求的（并且无法再延长的）子数组
            res = max(res,i - i0);
            i--;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int>nums = {42,43,44,43,44,43,44,45,46};
    cout << s.alternatingSubarray(nums) << endl;
    return 0;
}