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
        
    }
};

int main(){
    vector<int>nums = {3,4,-1,1};
    Solution s;
    cout << s.firstMissingPositive(nums) << endl;
}