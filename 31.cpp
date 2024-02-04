/**
 * @file 31.cpp 31. 下一个排列
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 2;
        // 1. 找到nums[i - 1] 第一个非降序的元素
        while (n >= 0 && nums[n] >= nums[n + 1]) {
            n--;
        }
        // 2. 找到满足条件的nums[j]  nums[i - 1] < nums[j] 第一个小于nums[i - 1] 的元素
        if (n >= 0) {
            int j = nums.size() - 1;
            while (j > n && nums[j] <= nums[n]) {
                j--;
            }
            // 3. 交换nums[i - 1] 和nums[j]
            swap(nums[n], nums[j]);
        }
        // 4. 逆序nums[i] ~ nums[n]
        reverse(nums.begin() + n + 1, nums.end());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.nextPermutation(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}