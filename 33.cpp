/**
 * @file 33.cpp 搜索旋转排序数组
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-17
 * @cite https://leetcode.cn/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return nums[0] == target? 0 : -1;
        int l = 0,r = n - 1;
        while(l <= r){
            int mid = l + ((r - l) >> 2);
            if(target == nums[mid]) return mid;
            // 0-mid不包含旋转
            if(nums[0] <= nums[mid]){
                // 常规的二分的步骤
                if(nums[0] <= target && target <= nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
            //包含旋转
            else{
                if(nums[mid] <= target && target <= nums[n-1]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};

int mian() {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int res = s.search(nums, target);
    cout << res << endl;
    return 0;
}
