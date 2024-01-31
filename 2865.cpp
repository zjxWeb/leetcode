/**
 * @file 2865.cpp2865. 美丽塔 I
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-24
 * https://leetcode.cn/problems/beautiful-towers-i/description/
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//我们可以枚举每一座塔作为最高塔，每一次向左右两边扩展，算出其他每个位置的高度，然后累加得到高度和 ttt。求出所有高度和的最大值即可。
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long res = 0;
        int n = maxHeights.size();
        for(int i = 0; i < n;i++){
            long long t = maxHeights[i];
            int y = t;
            // 向左
            for(int j = i - 1; ~j; j--){
                y = min(y,maxHeights[j]);
                t += y;
            }
            y = maxHeights[i];
            // 向右
            for(int j = i + 1; j < n; j++){
                y = min(y,maxHeights[j]);
                t += y;
            }
            res = max(res,t);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int>max = {5,3,4,1,1};
    cout << s.maximumSumOfHeights(max) << endl;
    return 0;
}

