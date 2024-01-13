/**
 * @file 2423.cpp 删除字符使频率相同
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/remove-letter-to-equalize-frequency/description/
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
#include <algorithm>

using namespace std;

class Solution {
public:  
    bool is_same(unordered_map<int, int> &cnt){
        int p = cnt.begin()->second;
        for(auto &[_,v] : cnt){
            if(v != p){
                return false;
            }
        }
        return true;
    }
    bool equalFrequency(string word) {
        int n = word.length();
        for(int i = 0; i < n; ++i){
            unordered_map<int, int> cnt;
            for(int j = 0; j < n; ++j)
                if(i != j) cnt[word[j] - 'a']++;
            if(is_same(cnt))return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    string word = "bac";
    cout << s.equalFrequency(word) << endl;
    return 0;
}

