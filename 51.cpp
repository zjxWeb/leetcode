/**
 * @file 51.cpp N 皇后
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/n-queens/description/
 * @version 0.1
 * @date 2023-12-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;// 记录结果
        vector<int>path(n);// 记录路径上的数
        vector<int>on_path(n);// 记录未选的数
        vector<int>diag1(2 * n - 1);// r +c 
        vector<int>diag2(2 * n - 1);// r - c
        // dfs
        function<void(int)> dfs = [&](int k){
            if(k == n){
                vector<string> board(n);// 记录棋盘
                for(int i = 0; i < n; ++i)board[i] = string(path[i],'.') + 'Q' + string(n - 1 - path[i],'.');
                ans.push_back(board);
                return;
            }
            for(int j = 0; j < n; j++){
                if(!on_path[j] && !diag1[k + j] &&!diag2[k - j + n -1]){ // k+j 右上 k-j 左上  n-1是为了避免负数
                    path[k] = j;
                    on_path[j] = diag1[k + j] = diag2[k - j + n -1] = true;
                    dfs(k+1);
                    on_path[j] = diag1[k + j] = diag2[k - j + n -1] = false;// 恢复现场
                }
            }
        };
        dfs(0);
        return ans;
    }
};

int main(){
    Solution s;
    int n = 4;
    auto res = s.solveNQueens(n);
    for(auto i : res){
        for(auto j : i){
            cout << j << endl;
        }
        cout << endl;
    }
    return 0;
}