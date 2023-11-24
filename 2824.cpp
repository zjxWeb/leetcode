/**
 * @file 2824.cpp 统计和小于目标的下标对数目
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-24
 * @cite https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/description/
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // 暴力
        // int n = nums.size();
        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] < target) {
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        // 双指针
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = 0,j = n -1;i < j;i++)
        {
            while(i < j && nums[i] + nums[j] >= target) j--;
            res += j - i;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int>nums = {-1,1,2,3,1};
    int target = 2;
    cout << s.countPairs(nums,target) << endl;
    return 0;
}   
