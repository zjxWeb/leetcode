#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int res = 0,flag = INT_MAX/10;
        int i = 0, sign = 1, len = s.length();
        if(len == 0) return 0;
        while(s[i] == ' ')
            if(++i == len) return 0;
        if(s[i] == '-') sign = -1;
        if(s[i] == '-' || s[i] == '+' ) i++;
        for(int j = i; j < len; j++){
            if(s[j] < '0' || s[j] > '9') break;
            if(res > flag || res == flag && s[j] > '7')
                return sign == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + (s[j] - '0');
        }
        return res * sign;
    }
};

int main() {
    Solution s;
    string s = "42";
    cout << s.myAtoi(s) << endl;
    return 0;
}