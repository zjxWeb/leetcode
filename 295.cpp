/**
 * @file 295.cpp数据流的中位数
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-100-liked
 * @version 0.1
 * @date 2023-12-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
    // 定义优先队列  小顶堆和大顶堆
    priority_queue<int,vector<int>,less<int>>queMin;
    priority_queue<int,vector<int>,greater<int>>queMax;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(queMin.empty() || num <= queMin.top()){
            queMin.push(num);
            // 如果quemax 数量大于 quemin 数量 则将quemin的最大值放入quemax
            if(queMax.size() + 1 < queMin.size()){
                queMax.push(queMin.top());
                queMin.pop();
            }
        }else{
            queMax.push(num);
            if(queMax.size() > queMin.size()){
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        // min 大于 max 说明中位数在小队列的最大值，此时为奇数
        if(queMin.size() > queMax.size()) return queMin.top();
        else return (queMin.top() + queMax.top()) / 2.0;
    }
};

int main() {
    MedianFinder * medianFinder = new MedianFinder();
    medianFinder->addNum(1);    // arr = [1]
    medianFinder->addNum(2);    // arr = [1, 2]
    cout << medianFinder->findMedian() << endl; // 返回 1.5 ((1 + 2) / 2)
    medianFinder->addNum(3);    // arr[1, 2, 3]
    cout << medianFinder->findMedian() << endl; // return 2.0
}