/**
 * @file 292.cpp Nim 游戏
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-04
 * https://leetcode.cn/problems/nim-game/description/
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if(n <= 3) return true;
        if(n % 4 == 0) return false;
        return true;
    }
};
int main(){
    int n = 4;
    Solution s;
    cout << s.canWinNim(n) << endl;
}
