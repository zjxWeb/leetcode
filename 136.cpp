/**
 * @file 136.cpp 136. 只出现一次的数字
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-20
 * https://leetcode.cn/problems/single-number/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int res = 0;
        for(int i = 0; i < n; i++){
            res ^= nums[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int>nums = {2,2,1};
    cout << s.singleNumber(nums) << endl;
}
