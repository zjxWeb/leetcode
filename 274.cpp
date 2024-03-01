/**
 * @file 274.cpp H 指数
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-28
 * https://leetcode.cn/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>cnt(n+1);
        for(auto el : citations) cnt[min(el,n)]++; // 引用次数大于n，等价于引用次数为n
        int s = 0;
        for(int i = n;; i--){
            s += cnt[i];
            if(s >= i) return i; 
        }
    }
};

int main(){
    Solution s;
    vector<int> citations = {3,0,6,1,5};
    cout << s.hIndex(citations) << endl;
    return 0;
}