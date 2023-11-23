#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        if( n == 0 ) return 0;
        // vector<vector<int>>dp(n,vector<int>(5,0));
        // dp[i][j]——第i天，状态j所剩最大现金
        // i 表示是第i天
        // j表示0-4的五种状态  0：没有操作，  1：第一次持有  2：第一次不持有  3：第二次持有  4：第二次不持有
        // dp[0][1] = -prices[0];
        // dp[0][3] = -prices[0];
        // for (int i = 1; i < n; i++)
        // {
        //     dp[i][0] = dp[i-1][0];
        //     dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
        //     dp[i][2] = max(dp[i-1][2],dp[i-1][1] + prices[i]);
        //     dp[i][3] = max(dp[i-1][3],dp[i-1][2] - prices[i]);
        //     dp[i][4] = max(dp[i-1][4],dp[i-1][3] + prices[i]);
        // }
        // return dp[n-1][4];
        vector<int>dp(5,0);
        dp[1] = -prices[0];
        dp[3] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[0] = dp[0];
            dp[1] = max(dp[1],dp[0] - prices[i]);
            dp[2] = max(dp[2],dp[1] + prices[i]);
            dp[3] = max(dp[3],dp[2] - prices[i]);
            dp[4] = max(dp[4],dp[3] + prices[i]);
        }
        return dp[4];
    }
};

int main(){
    vector<int>prices = {3,3,5,0,0,3,1,4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
}