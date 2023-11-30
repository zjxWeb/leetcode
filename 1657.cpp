/**
 * @file 1657.cpp 确定两个字符串是否接近
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-30
 * @cite https://leetcode.cn/problems/determine-if-two-strings-are-close/description/
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26), v2(26);
        for(auto el : word1) v1[el - 'a']++;
        for(auto el : word2) v2[el - 'a']++;
        for(int i = 0; i < 26; i++)if(v1[i]>0 && v2[i] == 0 ||  v1[i]==0 && v2[i]>0 ) return false;
        sort(v1.begin(), v1.end());sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};

int main(){
    Solution s;
    string word1 = "cabbba", word2 = "abbccc";
    cout << s.closeStrings(word1, word2) << endl;
    return 0;
}