/*
    给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
    求在该柱状图中，能够勾勒出来的矩形的最大面积。

    示例 1:
    输入：heights = [2,1,5,6,2,3]
    输出：10
    解释：最大的矩形为图中红色区域，面积为 10

    示例 2：
    输入： heights = [2,4]
    输出： 4

    提示：
    1 <= heights.length <=105
    0 <= heights[i] <= 104
*/
#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>

using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int res = 0;
        st.push(0);
        int sum = 0;
        for (int i = 1; i < heights.size(); i++) {
            while (heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int h = heights[mid];
                res = max(res, w * h);
            }
            st.push(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int>num = {2,1,5,6,2,3};
    cout << s.largestRectangleArea(num) << endl;
}