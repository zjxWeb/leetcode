/**
 * @file 35.cpp 搜索插入位置
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * @cite   https://leetcode.cn/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + ((right - left) >> 2);
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 5;
    Solution s;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}