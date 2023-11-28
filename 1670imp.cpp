/**
 * @file 1670.cpp 设计前中后队列
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * @cite https://leetcode.cn/problems/design-front-middle-back-queue/description/
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <deque>

using namespace std;

class FrontMiddleBackQueue {
private:
    deque<int> left;
    deque<int> right;
    void balance(){
        if(left.size() > right.size()){
            right.push_front(left.back());
            left.pop_back();
        }
        else if (right.size() > left.size() + 1){
            left.push_back(right.front());
            right.pop_front();
        }
    }
public:
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if(left.size() < right.size()){
            left.push_back(val);
        }
        else{
            right.push_front(val);
        }
    }
    
    void pushBack(int val) {
        right.push_back(val);
        balance();
    }
    
    int popFront() {
        if(right.empty()) return -1; // 整个队列为空
        int val;
        if(left.empty()){
            val = right.front();
            right.pop_front();
        }
        else{
            val = left.front();
            left.pop_front();
        }
        balance();
        return val;
    }
    
    int popMiddle() {
        if (right.empty()) return -1;
        int val;
        if (left.size() == right.size()) {
            val = left.back();
            left.pop_back();
        } else {
            val = right.front();
            right.pop_front();
        }
        return val;
    }
    int popBack() {
        if(right.empty()) return -1;
        int val = right.back();
        right.pop_back();
        balance();
        return val;
    }
};


int main(){
    FrontMiddleBackQueue* q = new FrontMiddleBackQueue();
    q->pushFront(1);   // [1]
    q->pushBack(2);    // [1, 2]
    q->pushMiddle(3);  // [1, 3, 2]
    q->pushMiddle(4);  // [1, 4, 3, 2]
    cout << q->popFront()  << endl;    // 返回 1 -> [4, 3, 2]
    cout << q->popMiddle() << endl;    // 返回 3 -> [4, 2]
    cout << q->popMiddle() << endl;    // 返回 4 -> [2]
    cout << q->popBack()   << endl;    // 返回 2 -> []
    cout << q->popFront()  << endl;    // 返回 -1 -> [] （队列为空）
    return 0;
}