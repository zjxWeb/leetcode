/**
 * @file 2788.cpp 2788. 按分隔符拆分字符串
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/split-strings-by-separator/description/
 * @version 0.1
 * @date 2024-01-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include<sstream>  

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        // vector<string> res;
        // for(auto & el : words){
        //     int n = el.size(),i=0;
        //     while(i < n){
        //         if(el[i] == separator){
        //             i++;
        //             continue;
        //         }
        //         int start = i;
        //         i++;
        //         while(i < n && el[i] != separator)i++;
        //         res.push_back(el.substr(start, i-start));
        //     }
        // }
        // return res;

        vector<string>res;
        for(auto & el : words){
            istringstream iss(el);
            string temp;
            while(getline(iss, temp, separator)){
               if(!temp.empty()){
                 res.push_back(temp);
               }
            }
        }
        return res; 
    }
};

int main() {
    Solution s;
    vector<string> words = {"one.two.three","four.five","six"};
    char separator = '.';
    for(auto el : s.splitWordsBySeparator(words, separator)){
        cout << el << endl;
    }
}