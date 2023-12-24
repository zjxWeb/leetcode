/**
 * @file 46.cpp全排列
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/permutations/description/
 * @version 0.1
 * @date 2023-12-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n), on_path(n);
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!on_path[j]) {
                    path[i] = nums[j];
                    on_path[j] = true;
                    dfs(i + 1);
                    on_path[j] = false; // 恢复现场
                }
            }
        };
        dfs(0);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    auto res = s.permute(nums);
    for(auto i : res){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}