/**
 * @file 3.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-11
 * 
 * @copyright Copyright (c) 2023
 * 无重复字符的最长子串
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
 */

#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希表记录每个字符是否出现过
        unordered_set<char> oc;
        int n = s.size();
        int r = -1,ans = 0;
        for(int i = 0;i < n;i++){
            if(i) oc.erase(s[i-1]);
            while(r + 1 < n && !oc.count(s[r + 1])){
                oc.insert(s[r + 1]);
                ++r;
            }
            ans = max(ans,r - i + 1);
        }
        return ans;
    }
};
int main(){
    Solution s;
    string str = "abcabcbb";
    cout<<s.lengthOfLongestSubstring(str)<<endl;
}