/**
 * @file 1094.cpp  拼车
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * @cite https://leetcode.cn/problems/car-pooling/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include  <map>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 差分数组(第一种写法)
        int a[1001]{};
        for(auto &el : trips){
            int num = el[0],from = el[1],to = el[2];
            a[from] += num;
            a[to] -= num;
        }
        int s= 0;
        for(int i= 0;i<1001;i++){
            s += a[i];
            if(s > capacity) return false;
        }
        return true;

        // 差分数组(第二种写法)
        map<int,int> m;
        for(auto &el : trips){
            int num = el[0],from = el[1],to = el[2];
            m[from] += num;
            m[to] -= num;
        }
        int s = 0;
        for(auto [_,vallue]: m){
            s += vallue;
            if(s > capacity) return false;
        }
        return true;
    }   
};

int main(){
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    Solution s;
    cout << s.carPooling(trips, capacity) << endl;
    return 0;
}