/**
 * @file 79.cpp 单词搜索
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-07
 * @cite https://leetcode.cn/problems/word-search/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // 直接判断单词是否再 board 中
        row = board.size();
        col = board[0].size();
        for(int i = 0; i <row; i++){
            for(int j = 0; j < col; j++){
                // 找到第一个字符
                if(board[i][j] == word[0]) if(backtrack(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int row = 0, col = 0;
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j]!= word[k]) return false;
        if(k == word.size() - 1) return true;
        board[i][j] = '\0';
        // 上下左右去寻找
        if(backtrack(board, word, i+1, j, k+1) || backtrack(board, word, i-1, j, k+1) || backtrack(board, word, i, j+1, k+1) || backtrack(board, word, i, j-1, k+1)) return true;
        board[i][j] = word[k];
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << s.exist(board, word) << endl;
    return 0;
}