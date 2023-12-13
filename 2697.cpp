/**
 * @file 2697.cpp 字典序最小回文串
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-13
 * @cite https://leetcode.cn/problems/lexicographically-smallest-palindrome/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
       // 双指针
       int n = s.size();
       int l = 0,r = n -1;
       while(l < r){
           s[l] = s[r] = min(s[l],s[r]);
           l++;
           r--;
       }
       return s;
    }
};
int main(){
    Solution s;
    string str = "egcfe";
    cout << s.makeSmallestPalindrome(str) << endl;
    return 0;
}