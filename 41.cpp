/**
 * @file 41.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-16
 * 
 * @copyright Copyright (c) 2023
 * 缺失的第一个正数
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 

示例 1：

输入：nums = [1,2,0]
输出：3
示例 2：

输入：nums = [3,4,-1,1]
输出：2
示例 3：

输入：nums = [7,8,9,11,12]
输出：1
 

提示：

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int n = nums.size();
        // for(auto &  el : nums) if( el < 0 ) el = n + 1;
        // for(int i = 0; i < n; i++){
        //     int index = abs(nums[i]);
        //     if( index <= n ) nums[index - 1] = -abs(nums[index - 1]);
        // }
        // for (int i = 0; i < n; i++) if(nums[i] > 0) return i + 1;
        // return n + 1;

        //置换的方法
        int n = nums.size();
        for(int i = 0; i < n; i++) while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
        for(int i = 0; i < n; i++) if(nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};

int main(){
    vector<int>nums = {7,8,9,11,12};
    Solution s;
    cout << s.firstMissingPositive(nums) << endl;
}