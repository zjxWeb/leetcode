/**
 * @file 2696.cpp 删除子串后的字符串最小长度
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/description/
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        vector<char>st;
        for(auto & c: s){
            st.push_back(c);
            int n = st.size();
            if(n >= 2 && (st[n - 2] == 'A' && st[n - 1] == 'B' || st[n - 2] == 'C' && st[n - 1] == 'D') ){
                st.pop_back();
                st.pop_back();
            }
        }
        return st.size();
    }
};

int main(){
    Solution s;
    string st = "ABFCACDB";
    cout << s.minLength(st) << endl;
    return 0;
}
