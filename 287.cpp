/**
 * @file 287.cpp寻找重复数
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-04
 * https://leetcode.cn/problems/find-the-duplicate-number/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3,1,3,4,2};
    cout << s.findDuplicate(nums) << endl;
}    
