/**
 * @file 153.cpp 寻找旋转排序数组中的最小值
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-17
 * @cite https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n - 1;
        while(l < r){
            int mid = l + ((r - l) >> 2);
            if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};

int main () {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int res = s.findMin(nums);
    cout << res << endl;
    return 0;
}