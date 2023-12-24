/**
 * @file 1954.cpp  收集足够苹果的最小花园周长
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        // cbrt开三次方
        long long n = cbrt(neededApples / 4.0);
        if(2 * n * (n + 1) * (2 * n + 1) < neededApples) n++;
        return 8 * n;
    }
};

int main(){
    Solution s;
    cout << s.minimumPerimeter(1) << endl;
    return 0;
}