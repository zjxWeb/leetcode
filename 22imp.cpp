/**
 * @file 22.cpp 括号生成
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * @cite https://leetcode.cn/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream> 
#include <vector>
#include <string>

using namespace std;


// class Solution {
// private:
//     bool  valid(const string& str){
//         int balance = 0;
//         for(auto el : str){
//             if(el == '(') ++balance;
//             else --balance;
//             if(balance < 0) return false;
//         }
//         return balance == 0;
//     }
//     void generate(string& cur, int n, vector<string>& res){
//         // 递归出口
//         if(cur.size() == n){
//             if(valid(cur)) res.push_back(cur);
//             return;
//         }
//         cur += '(';
//         generate(cur,n,res);
//         cur.pop_back();
//         cur += ')';
//         generate(cur,n,res);
//         cur.pop_back();
//     }
// public:
//     // 暴力破解
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         string cur;
//         generate(cur,n*2,res);
//         return res;
//     }
// };

//回溯法
class Solution {
private:
    void backtracking(vector<string>& res, string& cur, int left, int right, int n){
        if(cur.size() == n*2){
            res.push_back(cur);
            return;
        }
        if(left < n){
            cur += '(';
            backtracking(res,cur,left+1,right,n);
            cur.pop_back();
        }
        if(right < left)
        {
            cur += ')';
            backtracking(res,cur,left,right+1,n);
            cur.pop_back();
        }
    }
public:
    // 暴力破解
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtracking(res,cur,0,0,n);
        return res;
    }
};
int main(){
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for(auto &e : res){
        cout << e << endl;
    }
    return 0;

}