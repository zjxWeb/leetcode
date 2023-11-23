#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n2,vector<int>(n1,0));
        
    }
};

int main()
{
    Solution s;
    string str = "abc", t = "ahbgdc";
    cout << s.isSubsequence(str,t) << endl;
    return 0;
}