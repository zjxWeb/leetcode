/**
 * @file 365.cpp365. 水壶问题
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-28
 * https://leetcode.cn/problems/water-and-jug-problem/description/
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        // 贝祖定理
        if(jug1Capacity + jug2Capacity < targetCapacity) return false;
        if(jug1Capacity == 0 || jug2Capacity == 0) return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};

int main() {
    Solution s;
    int jug1Capacity = 3;
    int jug2Capacity = 5;
    int targetCapacity = 4;
    bool res = s.canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);
    cout << res << endl;
}