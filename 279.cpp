#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT16_MAX);
        dp[0] = 0;
        // 背包 n
        for(int i = 0;i <=n ;i++)
        {
            //物品 j * j
            for(int j = 1; j * j <= i;j++)
            {
                dp[i] = min(dp[i - j * j] + 1,dp[i]);
            }
            cout << endl;
        }
        return dp[n];
    }
};

int main()
{
    int n = 5;
    Solution s;
    cout << s.numSquares(n) << endl;
    return 0;
}