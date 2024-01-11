/**
 * @file 416.cpp 分割等和子集
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=study-plan-v2&envId=top-100-liked
 * @version 0.1
 * @date 2024-01-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int sum = accumulate(nums.begin(),nums.end(),0);
       if(sum % 2 != 0) return false;
       int target = sum / 2;
        vector<int> dp(target+1,0);
        for(int i = 0; i < n; i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[target] == target) return true;
        else return false;
    }
};

int main(){
    vector<int> nums = {1,5,11,5};
    Solution s;
    cout << s.canPartition(nums) << endl;
    return 0;
}