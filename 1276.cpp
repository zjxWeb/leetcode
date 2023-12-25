/**
 * @file 1276.cpp 不浪费原料的汉堡制作方案
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients/
 * @version 0.1
 * @date 2023-12-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> res;
        int x = tomatoSlices - cheeseSlices * 2;
        if(x % 2 != 0) return res;
        x = x / 2;
        int y = cheeseSlices - x;
        if(x >= 0 && y >= 0){
            res.push_back(x);
            res.push_back(y);   
        }
        return res;
    }
};

int main(){
    Solution s;
    int tomatoSlices = 0, cheeseSlices = 0;
    auto res = s.numOfBurgers(tomatoSlices, cheeseSlices);
    for(auto el : res) cout << el << endl;
    return 0;
}
