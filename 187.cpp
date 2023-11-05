/**
 * @file 187.cpp
 * @author zjxweb (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-05
 * 
 * @copyright Copyright (c) 2023
 * 
 * DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。

    例如，"ACGAATTCCG" 是一个 DNA序列 。
    在研究 DNA 时，识别 DNA 中的重复序列非常有用。

    给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。

    

    示例 1：

    输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
    输出：["AAAAACCCCC","CCCCCAAAAA"]
    示例 2：

    输入：s = "AAAAAAAAAAAAA"
    输出：["AAAAAAAAAA"]
    

    提示：

    0 <= s.length <= 105
    s[i]=='A'、'C'、'G' or 'T'
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    const int LEN = 10;
    // 优化一下代码
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> m;
        int n = s.length();
        if(n <= LEN ) return res;
        for (int i = 0; i <= n - LEN; i++) 
        {
            // 裁剪
            string sub = s.substr(i, LEN);
            if(++m[sub] == 2) res.push_back(sub);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> res = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto i : res)
    {
        cout<<i<<endl;
    }
    return 0;
}