/**
 * @file 907.cpp 子数组的最小值之和
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * @cite https://leetcode.cn/problems/sum-of-subarray-minimums/description/
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // 单调栈
        int n = arr.size(),mod = 1e9 + 7;
        long long res = 0;
        stack<int> stk;
        vector<int>left(n, 0), right(n, 0);// 寻找左右两边第一个比它小的值
        // 寻找左侧
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            left[i] = stk.empty()? -1 : stk.top();
            stk.push(i);
        }
        // 寻找右侧
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            right[i] = stk.empty()? n : stk.top();
            stk.push(i);
        }
        // 计算所有子数组最小值之和
        // 如果我们知道 arr[i] 的左侧边界是 left[i]，右侧边界是 right[i]，那么 arr[i] 是 (i - left[i]) * (right[i] - i) 个子数组的最小值。
        // 这是因为从 left[i] + 1 到 i 有 (i - left[i]) 种选择，从 i 到 right[i] - 1 有 (right[i] - i) 种选择，这些选择定义了包含 arr[i] 
        // 并以其为最小值的所有子数组。

        // 假设有数组 [3, 1, 2, 4]，考虑元素 2
        //2 的左侧第一个比它小的元素是 1，位置为 1（索引从 0 开始）。
        // 2 的右侧第一个比它小的元素是不存在的，所以取数组长度 4。
        // 因此，2 是 (2 - 1) * (4 - 2) = 2 个子数组的最小值，分别是 [1, 2] 和 [1, 2, 4]。

        for (int i = 0; i < n; i++) {
            res += (i - left[i]) * (right[i] - i) * arr[i];
            res %= mod;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {71,55,82,55};
    cout << sol.sumSubarrayMins(arr) << endl;
    return 0;
}
