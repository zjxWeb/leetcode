/** 
 * @file 462.cpp 最小操作次数使数组元素相等 II
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-18
 * @cite https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/description/
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(nums[i] - nums[n/2]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,10,2,9};
    int ans = s.minMoves2(nums);
    cout << ans << endl;
    return 0;
}