#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n = strs.size();
    }
};

int main(){
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}