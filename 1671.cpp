/**
 * @file 1671.cpp得到山形数组的最少删除次数
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array/description/
 * @version 0.1
 * @date 2023-12-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = getLISArry(nums);
        vector<int> suf = getLISArry({nums.rbegin(),nums.rend()});
        reverse(suf.begin(),suf.end());
        int ans = 0;
        for(int i = 0; i < n; i++)if(pre[i] > 1 && suf[i] > 1) ans = max(ans,pre[i]+suf[i]-1);
        return n - ans;
    }
private:
    // 返回最长递增子序列的
    vector<int> getLISArry(const vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
};
int main(){
    Solution s;
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout << s.minimumMountainRemovals(nums) << endl;
    return 0;
}