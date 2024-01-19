/**
 * @file 1143.cpp 最长公共子序列
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=top-100-liked
 * @version 0.1
 * @date 2024-01-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string.h>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1));
        // for(int i = 1; i <= n1; i++){
        //     for(int j = 1; j <= n2; j++){
        //         if(text1[i-1] == text2[j-1]){
        //             dp[i][j] = dp[i-1][j-1] + 1;
        //         }else{
        //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n1][n2];

        // 记忆化搜索
        // int cache[n1][n2];
        // memset(cache, -1, sizeof(cache));
        // function<int(int,int)> dfs = [&](int i, int j ) -> int{
        //     if(i < 0 || j < 0) return 0;
        //     int &res = cache[i][j];
        //     if(res != -1) return res;
        //     if(text1[i] == text2[j]) return res = 1 + dfs(i-1, j-1);
        //     return res = max(dfs(i-1,j),dfs(i,j-1));
        // } ;
        // return dfs(n1-1, n2-1);

        // 翻译成递推
        // int f[n1+1][n2+1];
        // memset(f, 0, sizeof(f));
        // for(int i = 0; i < n1; i++){
        //     for(int j = 0; j < n2; j++){
        //         f[i+1][j+1] = text1[i] == text2[j] ? f[i][j] + 1 : max(f[i][j+1], f[i+1][j]);
        //     }
        // }
        // return f[n1][n2];

        // 空间优化
        int n1 = text2.size();
        // 空间优化
        int f[n1+1];
        memset(f, 0, sizeof(f));
        for(char &x : text1){
            for(int j = 0, pre = 0; j < n1;++j){
                int temp = f[j+1];
                f[j+1] = x == text2[j] ? pre +1 : max(f[j+1], f[j]);
                pre = temp;
            }
        }
        return f[n1];
    }
};

int main(){
    Solution s;
    string text1 = "abcde";
    string text2 = "ace";
    cout << s.longestCommonSubsequence(text1, text2) << endl;
}