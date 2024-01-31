/**
 * @file 2670.cpp2670. 找出不同元素数目差数组
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-31
 * https://leetcode.cn/problems/find-the-distinct-difference-array/description/
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        // 前缀 — 后缀
        // 前缀 前i个元素
        // 后缀 i+1 —— n -1的元素
        // 1. i - n-1 中不同元素的数据
        // 2. 前缀中出现过的元素
        int n = nums.size();
        vector<int> ans(n+1);
        unordered_set<int> set;
        for(int i = n - 1; i >= 0; i--){
            set.insert(nums[i]);
            ans[i] = set.size();
        }
        set.clear();
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            set.insert(nums[i]);
            res[i] = set.size() - ans[i + 1];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    for(auto el : s.distinctDifferenceArray(nums)){
        cout << el << endl;
    }
}