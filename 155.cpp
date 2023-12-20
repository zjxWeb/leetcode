/**
 * @file 155.cpp 最小栈
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-20
 * @cite https://leetcode.cn/problems/min-stack/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> s;
    stack<int> min_s;
public:
    MinStack() {
        min_s.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        min_s.push(min(min_s.top(), val));
    }
    
    void pop() {
        s.pop();
        min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

int main(int argc, char const *argv[])
{
    MinStack * minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin();   //--> 返回 -3.
    minStack->pop();
    cout << minStack->top();      //--> 返回 0.
    cout << minStack->getMin();   //--> 返回 -2.
}