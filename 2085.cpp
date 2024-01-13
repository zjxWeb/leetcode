/**
 * @file 2085.cpp  统计出现过一次的公共字符串
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/count-common-words-with-one-occurrence/description/
 * @version 0.1
 * @date 2024-01-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        // 统计字符串出现频率
        unordered_map<string, int> freq1, freq2;
        for (const string& w: words1) {
            ++freq1[w];
        }
        for (const string& w: words2) {
            ++freq2[w];
        }

        // 遍历 words1 出现的字符并判断是否满足要求
        int res = 0;
        for (const auto& [w, cnt1] : freq1) {
            if (cnt1 == 1 && freq2[w] == 1) {
                ++res;
            }
        }
        return res;
    }
};



int main()
{
    Solution s;
    vector<string> words1 = {"leetcode","is","amazing","as","is"};
    vector<string> words2 = {"amazing","leetcode","is"};
    cout << s.countWords(words1, words2) << endl;
}