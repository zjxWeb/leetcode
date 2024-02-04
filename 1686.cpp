/**
 * @file 1686.cpp1686. 石子游戏 VI
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-02
 * https://leetcode.cn/problems/stone-game-vi/description/
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(),ids.end(), [&](int i, int j) { return a[i] + b[i] > a[j] + b[j]; });
        int diff = 0;
        for (int i = 0; i < n; i++) {
            diff += i % 2 == 0 ? a[ids[i]] : -b[ids[i]];
        }
        return (diff > 0) - (diff < 0);
    }
};

int main(){
    vector<int>aliceValues = {1,3};
    vector<int>bobValues = {2,1};
    Solution s;
    cout << s.stoneGameVI(aliceValues, bobValues) << endl;
}