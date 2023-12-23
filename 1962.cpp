/**
 * @file 1962.cpp  移除石子使总数最小   
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/remove-stones-to-minimize-the-total/description/
 * @version 0.1
 * @date 2023-12-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <numeric>


using namespace std;


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // 原地堆化  大顶堆
        make_heap(piles.begin(), piles.end());
        while(k-- && piles[0]){
            pop_heap(piles.begin(), piles.end());// 弹出堆顶元素并移植堆尾
            // 进行/2
            piles.back() -= piles.back() / 2;
            // 堆尾元素入堆
            push_heap(piles.begin(), piles.end());
        }
        return accumulate(piles.begin(), piles.end(), 0);
    }
};
int main(){
    Solution s;
    vector<int> piles = {5, 3, 1, 4, 2};
    int k = 2;
    cout << s.minStoneSum(piles, k) << endl;
    return 0;
}