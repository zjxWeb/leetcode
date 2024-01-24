/**
 * @file 169.cpp 169. 多数元素
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-20
 * https://leetcode.cn/problems/majority-element/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int tmp = n / 2;
        unordered_map<int,int>count;
        for(auto &el : nums){
            count[el]++;
        }
        // 遍历count 如果存在value > tmp/2 则返回key
        for(auto [k,v] : count){
            if(v > tmp) return k;
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int>nums = {2,2,1,1,1,2,2};
    cout << s.majorityElement(nums) << endl;
}