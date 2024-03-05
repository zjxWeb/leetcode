#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        int res = 0;
        while(x){
            if (res < INT_MIN / 10 || res > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main() {
    Solution s;
    int x = -1534236469;
    cout << s.reverse(x) << endl;
    return 0;
}