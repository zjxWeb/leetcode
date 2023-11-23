#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j]为true表示回文串
        int n = s.size();
        int res = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        // 遍历从下到上，从左到右
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    if(j - i <= 1){
                        res++;
                        dp[i][j] = true;
                    }
                    else if( dp[i+1][j-1]){// 类似双指针
                        res++;
                        dp[i][j] = true;
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }
            
        }
        return res;
        
    }
};

int main()
{
    Solution st;
    string s = "abc";
    cout << st.countSubstrings(s) << endl;
}