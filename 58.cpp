#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n - 1;
        while(i >= 0 && s[i] == ' ') i--;
        int j = i;
        while(j >= 0 && s[j] != ' ') j--;
        return i - j;
    }
};

int main(){
    Solution s;
    string s1 = "Hello World";
    cout << s.lengthOfLastWord(s1) << endl;
    return 0;
}