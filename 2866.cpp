/**
 * @file 2866.cpp 美丽塔 II
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/beautiful-towers-ii/description/
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

/**
 * 要点
 * 1. 相同的数，只需要保留最靠左的那一个的小标
 * 2. 用单调栈维护需要保留的数
 * 
 * 3. 如何维护sum
 */

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long sum = 0;
        stack<int>st;
        st.push(n); // 哨兵
        vector<long long> suf(n + 1);
        // 倒着遍历数组
        for(int i = n - 1; i >= 0; i--){
            int x = maxHeights[i];
            while(st.size() > 1 && x <= maxHeights[st.top()]){
                int j = st.top();
                st.pop();
                // 比如 6 5 3 9 2 7 7 7 
                // 需要弹出777  7 的 个数 =   n - (n -3)  maxHeights[j]——7
                sum -= (long long) maxHeights[j] * (st.top() - j); // 撤销之前加到 sum 中的
            }
            sum += (long long) x * (st.top() - i); // 从 i 到 st.top()-1 都是 x
            suf[i] = sum;
            st.push(i);
        }
        // 从左到右
        long long ans = sum;
        st = stack<int>();
        st.push(-1);
        long long pre = 0;
        for(int i = 0; i < n; i++){
            int x = maxHeights[i];
            while(st.size() > 1  && x <= maxHeights[st.top()]){
                int j = st.top();
                st.pop();
                pre -= (long long) maxHeights[j] * (j - st.top()); // 撤销之前加到 pre 中的
            }
            pre += (long long) x * (i - st.top());
            ans = max(ans, pre + suf[i + 1]);
            st.push(i);
        }
        return ans;        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {3,5,3,5,1,5,4,4,4};
    cout << s.maximumSumOfHeights(v) << endl;
    return 0;
}