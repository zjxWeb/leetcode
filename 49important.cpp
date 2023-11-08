/**
 * @file 49.cpp
 * @author zjxweb (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 49. 字母异位词分组
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
    字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

    示例 1:
    输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

    示例 2:
    输入: strs = [""]
    输出: [[""]]

    示例 3:
    输入: strs = ["a"]
    输出: [["a"]]
    

    提示：
    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] 仅包含小写字母
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace  std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(auto& str : strs){
            string key = str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        for(auto& [key,value] : mp)res.push_back(value);
        return res;
    }
};
int main(){
    Solution s;
    vector<string>strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for(auto el : s.groupAnagrams(strs))
    {
        for(auto e : el) cout << e << endl;
    }
}

