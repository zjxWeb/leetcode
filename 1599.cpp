#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {\
        int res = -1,value = 0,max = 0,p = 0;
        for(int i = 0;i < customers.size() || p > 0;i++){
            if(i < customers.size()) p += customers[i];
            value += min(p,4) * boardingCost - runningCost;
            p -= min(p,4);
            if(value > max){
                max = value;
                res = i + 1;
            }
        }
        return res;
    }
};

int main(){
    vector<int>customers  = {8,3};
    int boardingCost = 5, runningCost = 6;
    Solution s;
    cout << s.minOperationsMaxProfit(customers, boardingCost, runningCost) << endl;
}