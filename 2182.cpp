/**
 * @file 2182.cpp 构造限制重复的字符串
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/construct-string-with-repeat-limit/description/
 * @version 0.1
 * @date 2024-01-13
 * C++ int 是signed  所以说 i >= 0 和 ~i 是等价的
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        int cnt[26]{};
        for(char & c : s) ++cnt[c - 'a'];
        for (int i = 25, j = 24; ~i; --i) {
            j = min(j, i - 1);
            while (1) {
                for (int k = min(cnt[i], repeatLimit); k; --k) {
                    res += 'a' + i;
                    --cnt[i];
                }
                if (cnt[i] == 0) {
                    break;
                }
                while (j >= 0 && cnt[j] == 0) {
                    --j;
                }
                if (j < 0) {
                    break;
                }
                res += 'a' + j;
                --cnt[j];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string st = "cczazcc";
    int repeatLimit = 3;
    cout << s.repeatLimitedString(st, repeatLimit) << endl;
    return 0;
}