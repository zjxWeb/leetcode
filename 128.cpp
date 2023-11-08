/**
 * @file 128.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-08
 * 
 * @copyright Copyright (c) 2023
 * 128. 最长连续序列
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 示例 1：

    输入：nums = [100,4,200,1,3,2]
    输出：4
    解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
    示例 2：

    输入：nums = [0,3,7,2,5,8,4,6,0,1]
    输出：9
    

    提示：
    0 <= nums.length <= 105
    -109 <= nums[i] <= 109

 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums.empty()) return 0;
        if(n == 1) return 1;
        int countMax = 1;// 统计连续的次数
        int curLen = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if(abs(nums[i+1] - nums[i]) == 1)curLen++;
            else if (nums[i + 1] == nums[i]) continue;
            else curLen = 1;
            countMax = max(countMax, curLen);
        }
        return countMax;
    }
};
int main(){
    Solution s;
    vector<int>nums = {0,3,7,2,5,8,4,6,0,1};
    cout << s.longestConsecutive(nums);
}