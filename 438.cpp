/**
 * @file 438.cpp
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-12
 * 
 * @copyright Copyright (c) 2023
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 

提示:

1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()) return res;
        //  统计p中的字母次数
        vector<int> counts(26,0);
        for(int i = 0; i < p.size(); i++){
            counts[p[i] - 'a']++;
        }
        //  统计s中的字母次数
        vector<int> window(26,0);
        for (int i = 0; i < p.size() -1; i++)
        {
            window[s[i] - 'a']++;
        }
        for(int l = 0,r = p.size() - 1;r < s.size();l++,r++){
            window[s[r] - 'a']++;
            if(window == counts) res.push_back(l);
            window[s[l] - 'a']--;
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "cbaebabacd";
    string p = "abc";
    for(auto el : s.findAnagrams(str,p))
    {
        cout << el << endl;
    }
}