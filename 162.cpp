/**
 * @file 162.cpp 寻找峰值
 * @author your name (you@domain.com)
 * @brief  
 * @version 0.1
 * @date 2023-12-18
 * @cite https://leetcode.cn/problems/find-peak-element/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 二分法
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 2);
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;

    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}