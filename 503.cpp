/*
    503. 下一个更大元素 II
    给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。
    数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。

    示例 1:
    输入: nums = [1,2,1]
    输出: [2,-1,2]
    解释: 第一个 1 的下一个更大的数是 2；
    数字 2 找不到下一个更大的数； 
    第二个 1 的下一个最大的数需要循环搜索，结果也是 2。

    示例 2:
    输入: nums = [1,2,3,4,3]
    输出: [2,3,4,-1,4]
    
    提示:
    1 <= nums.length <= 104
    -109 <= nums[i] <= 109
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,-1);
        stack<int>st; // 下标元素
        st.push(0);
        if (nums.size() == 0) return res;
        for (int i = 0; i < n * 2; i++)
        {
            // 模拟遍历两边nums，注意一下都是用i % nums.size()来操作  相当于遍历两边的nums数组
           while (!st.empty() && nums[i % nums.size()] > nums[st.top()])
           {
             res[st.top()] = (nums[i % nums.size()]);// 覆盖的是对应下表的元素
             st.pop();
           }
           st.push(i % nums.size());
           
        }
        return res;
        
    }
};

int main(){
    Solution s;
    vector<int>num = {1,2,1};
    for(auto el : s.nextGreaterElements(num)){
        cout << el << endl;
    }
}