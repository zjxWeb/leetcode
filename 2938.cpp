/**
 * @file 2938.cpp 区分黑球与白球
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-23
 * @cite https://leetcode.cn/problems/separate-black-and-white-balls/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long int res = 0,counts = 0;
        // 统计左边出现的1的个数
        for (int i = 0; i < n; i++) {
            if(s[i] == '0') res += counts;
            else counts++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s = "101";
    cout << sol.minimumSteps(s) << endl;
    return 0;
}