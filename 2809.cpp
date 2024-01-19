/**
 * @file 2809.cpp 使数组和小于等于 x 的最少时间
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/description/
 * @version 0.1
 * @date 2024-01-19
 * @copyright Copyright (c) 2024
 * 种菜，收菜问题
 * 1. 答案最大是多少？ n
 * 2. 从小到大枚举
 * 
 * t = 1 选一个当前最高的
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>dp(n+1,0);
        vector<pair<int,int>>nums(n);//保证了nums1和nums2的对应关系
        for(int i = 0; i < n; i++) nums[i] = {nums2[i],nums1[i]};
        // 排序
        sort(nums.begin(), nums.end());
        for(int j = 1; j <= n; j++){
            int b = nums[j-1].first, a = nums[j - 1].second;
            for(int i = j; i > 0; i--){
                // dp[j][i] = max(dp[j-1][i],dp[j-1][i-1] + i*b + a);
                dp[i] = max(dp[i],dp[i-1] + i * b + a);
            }
        }
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        for(int i = 0; i <= n; i++){
            if(sum2 * i + sum1 - dp[i] <= x) return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,2,3};
    int x = 4;
    cout << s.minimumTime(nums1, nums2, x) << endl;
    return 0;
}