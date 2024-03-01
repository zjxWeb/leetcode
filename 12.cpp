#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const pair<int,string> digitalString[] = {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string res;
        while(num){
            for(auto el : digitalString){
                if(num >= el.first){
                    res += el.second;
                    num -= el.first;
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.intToRoman(1994);
    return 0;
}