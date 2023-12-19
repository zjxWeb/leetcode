/**
 * @file 4.cpp 寻找两个正序数组的中位数
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-19
 * @cite https://leetcode.cn/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. 合并数组
        int n1 = nums1.size(),n2 = nums2.size();
        nums1.resize(n1+n2,0);
        int count = 0;
        for(int i = n1; i < n1 + n2; i++) nums1[i] = nums2[i - n1];
        sort(nums1.begin(),nums1.end());
        // 2. 计算中位数
        double median;
        int n = nums1.size();
        if(n % 2 == 0) median = (nums1[n/2] + nums1[n/2 - 1]) / 2.0;
        else median = nums1[n/2];
        return median;
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3,4};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}