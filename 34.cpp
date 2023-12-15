/**
 * @file 34.cpp 在排序数组中查找元素的第一个和最后一个位置
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * @cite https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 二分查找
        // 如果有两个值的时候怎么办那
        if (nums.size() == 0) return {-1,-1};
        int l = 0,r = nums.size() - 1;
        vector<int> res = {-1,-1};
        while (l <= r)
        {
            int mid = l + ((r - l) >> 2);
            if (nums[mid] == target)
            {
                res.erase(res.begin(),res.end());
                // 左边界
                while (mid > 0 && nums[mid] == nums[mid-1]) mid--;
                res.push_back(mid);
                // 右边界
                while (mid < nums.size() - 1 && nums[mid] == nums[mid+1]) mid++;
                res.push_back(mid);
                return res;
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> res = s.searchRange(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}