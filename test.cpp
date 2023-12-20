#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n = temperatures.size();
        vector<int>res(n, 0);
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }  
            st.push(i);
        }
        return res;
    }
};
int main(){
   Solution s;
   vector<int> nums = {73,74,75,71,69,72,76,73};
   s.dailyTemperatures(nums);
   return 0;
}