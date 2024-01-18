/**
 * @file 2171.cpp 拿出最少数目的魔法豆
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/removing-minimum-number-of-magic-beans/description/
 * @version 0.1
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long sum = accumulate(beans.begin(), beans.end(), 0);
        long long res = sum;
        sort(beans.begin(), beans.end());
        for(int i = 0; i < n; i++){
            res = min(res, sum - (long long)beans[i] * (n - i));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int>beans = {2,10,3,2};
    cout << s.minimumRemoval(beans) << endl;
}