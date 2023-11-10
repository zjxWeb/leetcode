/**
 * @file 11.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
    返回容器可以储存的最大水量。
    说明：你不能倾斜容器。

    输入：[1,8,6,2,5,4,8,3,7]
    输出：49 
    解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49

    示例 2：
    输入：height = [1,1]
    输出：1
    提示：
    n == height.length
    2 <= n <= 105
    0 <= height[i] <= 104
 */
#include<iostream>
#include<vector>
using namespace std;

// 接雨水双指针思路
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int sum = 0;
//         int count = 0;
//         if(n <= 2)  return 0;
//         vector<int>maxLeft(n,0);
//         vector<int>maxRight(n,0);
//         // 左柱子高度
//         maxLeft[0] = height[0];
//         for (int i = 1; i < n; i++) maxLeft[i] = max(height[i],maxLeft[i-1]);
//         maxRight[0] = height[n-1];
//         for (int i = n - 2; i >= 0; i--) maxRight[i] = max(height[i],maxRight[i+1]);
//         // 求和
//         for (int i = 0; i < n; i++)
//         {
//             count = min(maxLeft[i],maxRight[i] - height[i]);
//             sum += count;
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size(),l = 0,r = n -1,res = 0;
       while (l < r) (height[l] < height[r]) ? res = max(res,( r - l ) * height[l++]) : res = max(res,( r - l ) * height[r--]);
       return res;
    }
};
int main(){
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height) << endl;
    return 0;
}