/**
 * @file 1901.cpp 寻找峰值 II
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat.size() - 2;// 将整个二维从中间分开
        while(l <= r){
            int mid = l + ((r - l) / 2);
            int mid_x = indexOfMax(mat[mid]);
            if(mat[mid][mid_x] > mat[mid + 1][mid_x]) r = mid - 1;
            else l = mid + 1;
        }
        return {l,indexOfMax(mat[l])};
    }
private:
    int indexOfMax(vector<int> &a){
        return max_element(a.begin(),a.end()) - a.begin();
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{1,4},{3,2}};
    vector<int> res = s.findPeakGrid(mat);
    for(auto el : res) cout << el << " ";
    cout << endl;
    return 0;
}