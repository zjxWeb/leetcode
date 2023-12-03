/**
 * @file 1423.cpp 可获得的最大点数
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * @cite https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <numeric>


using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        // 滑动窗口
        // accumulate(起始迭代器, 结束迭代器, 初始值, 自定义操作函数)
        int win = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + win, 0); //右侧前k个数之和
        int minSum = sum;
        for (int i = win; i < n; i++) {
            // 滑动窗口每向右移动一格，增加从右侧进入窗口的元素值，并减少从左侧离开窗口的元素值
            sum = sum + cardPoints[i] - cardPoints[i - win];
            minSum = min(minSum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
    }
};

int main(){
    vector<int> cardPoints = {100,40,17,9,73,75};
    int k = 3;
    Solution sol;
    cout << sol.maxScore(cardPoints, k) << endl;

}