#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class MyQueue {
public:
    stack<int> in,out;
    MyQueue() {
    
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            } 
        }
        int res = out.top();
        out.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        out.push(res);
        return res;
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    cout << param_2 << " " << param_3 << " " << param_4 << endl;
}