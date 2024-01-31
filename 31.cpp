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
        int n = nums.size();
        
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