/**
 * @file 80.cpp0. 删除有序数组中的重复项 II
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-28
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @copyright Copyright (c) 2024
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicatesHelp(vector<int>& nums,int len){
        int n = 0;
        for(auto& el : nums) {
            int a =  nums[n-len];
             if(n < len || nums[n - len] != el) {
                nums[n++] = el;
             }
        }
        return n;
    }
    int removeDuplicates(vector<int>& nums) {
       return removeDuplicatesHelp(nums,2);
    }
};

int main(){
    Solution s;
    vector<int>nums = {0,0,1,1,1,1,2,3,3};
    cout << s.removeDuplicates(nums) << endl;
}