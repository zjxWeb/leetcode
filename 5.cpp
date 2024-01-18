/**
 * @file 5.cpp  最长回文子串
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-100-liked
 * @version 0.1
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string res;
    string longestPalindrome(string s) {
       
        // string res = s.substr(0,1);
        // for(int i = 0; i < s.size(); i++){
        //     for(int j = i; j < s.size(); j++){
        //         if(j - i + 1 > res.size() && isPalindrome(s, i, j)){
        //             res = s.substr(i, j - i + 1);
        //         }
        //     }
        // }
        // return res;

         // 动态规划
        // i == j  只有一个字符 true
        // s[i] == s[j]  0 < j-i <= 2  
        // s[i]== s[j] && P(i +1 ,j+1) j-i > 2
        // string res = s.substr(0,1);
        // vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        // // 从后往前
        // for(int i = s.size() - 1; i >= 0; i--){
        //     for(int j = i + 1; j < s.size(); j++){
        //         if(j == i) dp[i][j] = true;
        //         else if(j - i <= 2){
        //             dp[i][j] = s[i] == s[j];
        //         }else{
        //             dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
        //         }
        //         if(dp[i][j]  && j - i + 1 > res.size()){
        //             res = s.substr(i, j - i + 1);
        //         }
        //     }
        // }
        // return res;

        // 中心扩散法
        res = s.substr(0,1);
        // ABA  ABBA
        for(int i = 0; i < s.size(); i++){
            extemd(s, i, i);
            extemd(s, i, i + 1);
        }
        return res;
    }
    void extemd(string & s, int l ,int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        if(r - l - 1 > res.size()){
            res = s.substr(l + 1, r - l - 1);
        }
    }
// private:
//     // 判断是否是回文串
//     bool isPalindrome(string s,int l, int r) {
//         while(l <= r){
//             if(s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
};

int main() {
    Solution s;
    string str = "babad";
    string res = s.longestPalindrome(str);
    cout << res << endl;
    return 0;
}