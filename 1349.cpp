/**
 * @file 1349.cpp 参加考试的最大学生数
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/maximum-students-taking-exam/description/
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        
    }
};

int main(){
    Solution s;
    vector<vector<char>> seats = { 
                                    {'#','.','#','#','.','#'},
                                    {'.','#','#','#','#','.'},
                                    {'#','.','#','#','.','#'}
                                    };
    cout << s.maxStudents(seats) << endl;
    return 0;
}
