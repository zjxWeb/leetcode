/**
 * @file 2744.cpp 最大字符串配对数目
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/find-maximum-number-of-string-pairs/description/
 * @version 0.1
 * @date 2024-01-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            if (seen.count(words[i][1] * 100 + words[i][0])) {
                ++ans;
            }
            seen.insert(words[i][0] * 100 + words[i][1]);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words = {"cd","ac","dc","ca","zz"};
    cout << s.maximumNumberOfStringPairs(words) << endl;
}