/**
 * @file 670.cpp 最大交换
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-22
 * https://leetcode.cn/problems/maximum-swap/
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        int maxIndex = n-1;//维护最大值的下标
        int p = -1,q;
        // 倒序
        for (int i = n-2; i >= 0; i--)
        {
            if (str[i] > str[maxIndex])
            {
                maxIndex = i;
            }
            else if (str[i] < str[maxIndex])
            {
                p = i;
                q = maxIndex;// 更新 p 和 q
            }
        }
        if (p != -1)
        {
            swap(str[p], str[q]);
            return stoi(str);
        }
         // 这意味着 s 是降序的
        else
        {
            return num;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int num = 2736;
    int res = s.maximumSwap(num);
    cout << res << endl;
    return 0;
}