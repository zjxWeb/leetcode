/**
 * @file 166.cpp 分数到小数分数到小数
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * @cite https://leetcode.cn/problems/fraction-to-recurring-decimal/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 转 long 计算，防止溢出
        long a = numerator, b = denominator;
        
        // 本身能够整除，
        if (a % b == 0) return to_string(a / b);
        
        string result;
        
        // 负数
        if (a * b < 0) result += '-';
        
        a = abs(a);
        b = abs(b);
        
        // 计算小数点前的部分，并将余数赋值给 a
        result += to_string(a / b) + ".";
        a %= b;
        
        unordered_map<long, int> map;
        
        while (a != 0) {
           // 记录当前余数所在答案的位置，并继续模拟除法运算
            map[a] = result.length();
            a *= 10;
            result += to_string(a / b);
            a %= b;
            
            // 如果当前余数之前出现过，则将 [出现位置 到 当前位置] 的部分抠出来（循环小数部分）
            if (map.count(a) > 0) {
                int u = map[a];
                return result.substr(0, u) + "(" + result.substr(u) + ")";
            }
        }
        
        return result;
    }
};


int main(){
    Solution s;
    int numerator = 4;
    int denominator = 333;
    cout << s.fractionToDecimal(numerator, denominator) << endl;
    return 0;
}