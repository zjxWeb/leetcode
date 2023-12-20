/**
 * @file 394.cpp字符串解码
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-20
 * @cite https://leetcode.cn/problems/decode-string/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return backtracking(s,index);
    }
private:
    string backtracking(string s,int& index){
        string res;
        int num = 0;
        string tmp;
        while (index < s.size())
        {
            if (s[index] >= '0' && s[index] <= '9') num = num * 10 + s[index] - '0';
            else if (s[index] == '[')
            {
                tmp = backtracking(s,++index);
                while(num-->0) res += tmp; //while( (num--) > 0 )
                num = 0;
            }
            //结束递归
            else if (s[index] == ']') break;
            else  res += s[index];
            index++;
        }
        return res;
    }
};

int main() {
    Solution s;
    string s1 = "3[a]2[bc]";
    cout << s.decodeString(s1) << endl;
}