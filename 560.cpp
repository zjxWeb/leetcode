/**
 * @file 560.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-12
 * 
 * @copyright Copyright (c) 2023
 * 和为 K 的子数组
 * 
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。

 

示例 1：

输入：nums = [1,1,1], k = 2
输出：2
示例 2：

输入：nums = [1,2,3], k = 3
输出：2
 

提示：

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int n = nums.size();
        // int counts = 0;
        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for (int j = i; j >= 0; j--)
        //     {
        //         sum += nums[j];
        //         if(sum == k) counts++;
        //     }
        // }
        // return counts;
        // 建立哈希表 mp\textit{mp}mp，以和为键，出现次数为对应的值，
        unordered_map<int,int>mp;
        mp[0] = 1;
        int count = 0,pre = 0;
        for(auto & el : nums){
            pre += el;
            if(mp.find(pre-k) != mp.end()){
                count += mp[pre-k];
            }   
            mp[pre]++;
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1,1,1};
    int k = 2;
    Solution solution;
    cout << solution.subarraySum(nums, k) << endl;
}