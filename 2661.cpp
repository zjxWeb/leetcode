/**
 * @file 2661.cpp 找出叠涂元素
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-01
 * @cite https://leetcode.cn/problems/first-completely-painted-row-or-column/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // 存储每一个元素的位置
        unordered_map<int,pair<int,int>>m1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                m1[mat[i][j]] = {i,j};
            }
        }

        // 声明行和列，来记录这一行和这一列是否完成图色
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0; i < arr.size(); i++){
            auto& p = m1[arr[i]];
            ++row[p.first];
            if(row[p.first] == m) return i;
            ++col[p.second];
            if(col[p.second] == n) return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4},{2,3}};
    cout << s.firstCompleteIndex(arr, mat) << endl;
    return 0;
}
