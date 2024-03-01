#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string>res(numRows);
        int i = 0,flag = -1;
        for(auto el : s){
            res[i].push_back(el);
            if(i == 0 || i == numRows - 1) flag = -flag;
            i += flag;
        }
        string resStr;
        for(auto el : res) resStr += el;
        return resStr;
    }
};
int main(){
    Solution s;
    string sl = "LEECOD";
    int numRows = 3;
    cout << s.convert(sl,numRows) << endl;
    return 0;
}