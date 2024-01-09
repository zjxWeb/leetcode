#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();

        unordered_set<string>set(dictionary.begin(),dictionary.end());
        vector<int>f(n+1);
        for(int i  = 0;i < n ; i++){
            f[i+1]  = f[i] + 1;
            for(int j = 0; j <= i; j++){
                if(set.find(s.substr(j, i-j+1)) != set.end()){
                    f[i+1] = min(f[i+1], f[j]);
                }
            }
        }
        return f[n];
    }
};

int main() {
    Solution s;
    string st = "leetscode";
    vector<string>dictionary = {"leet","code","leetcode"};
    cout << s.minExtraChar(st, dictionary) << endl;
    return 0;
}