/**
 * 整数转罗马数字
 * https://leetcode.cn/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;// 存储答案
        int n = s.length();
        unordered_map<char,int> digitalMap = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
            };// 将涉及到参考的值放到哈希表中
        for( int i = 0; i < n; i++){
            if(i + 1 < n && digitalMap[s[i]] < digitalMap[s[i+1]]){// 如果当前值小于下一个值，就减去当前值
                res -= digitalMap[s[i]];
            }else{
                res += digitalMap[s[i]];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.romanToInt("III");
    return 0;
}