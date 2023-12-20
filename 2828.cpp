/**
 * @file 2828.cpp 判别首字母缩略词
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-20
 * @cite https://leetcode.cn/problems/check-if-a-string-is-an-acronym-of-words/description/
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        // vector<string> acronym;
        // string str;
        // for (int i = 0; i < words.size(); i++)acronym.push_back(words[i].substr(0, 1));
        // for (auto el : acronym) str += el;
        // return str == s;


        int n = words.size();
        if(n != s.size()) return false;
        for(int i = 0; i < n; i++) if(words[i][0]!= s[i]) return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> words = {"alice", "bob", "charlie"};
    string str = "abc";
    cout << s.isAcronym(words, str) << endl;
    return 0;
}
