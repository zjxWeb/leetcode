#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = nums[0];
        if(n == 1) return nums[0];
        int res = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i-1] + nums[i],nums[i]);
            if(dp[i] > res) res = dp[i];// res保存最大值
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
}