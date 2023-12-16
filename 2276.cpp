/**
 * @file 2276.cpp  统计区间中的整数数目
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-16
 * @cite https://leetcode.cn/problems/count-integers-in-intervals/description/
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

using namespace std;

class CountIntervals {
    CountIntervals *L = nullptr,*R = nullptr;
    //线段树的每个节点可以保存对应范围的左右端点 l和 r，以及范围内 add 过的整数个数 cnt。
    int l,r,cnt = 0;
public:
    CountIntervals() : l(1),r(1e9) {}
    CountIntervals(int l, int r) : l(l),r(r) {} 
    
    void add(int left, int right) {
        if(cnt == r - l + 1) return; // 如果已经添加完了，则不再添加
        if(left <= l && r <= right){
            // 当前节点已被区间 [left,right] 完整覆盖，不再继续递归
            cnt = r - l + 1;
            return;
        }
        int mid = l + ((r - l) >> 2);
        if(L == nullptr ) L = new CountIntervals(l,mid); // 左子树为空时，创建左子树
        if(R == nullptr ) R = new CountIntervals(mid+1,r); // 右子树为空时，创建右子树
        if(left <= mid) L->add(left,right);
        if(right > mid) R->add(left,right);
        cnt = L->cnt + R->cnt;
    }
    
    int count() {
        return cnt;
    }
};

int main(){
    CountIntervals  * countIntervals = new CountIntervals(); // 用一个区间空集初始化对象
    countIntervals->add(2, 3);  // 将 [2, 3] 添加到区间集合中
    countIntervals->add(7, 10); // 将 [7, 10] 添加到区间集合中
    cout << countIntervals->count() << endl;    // 返回 6
                            // 整数 2 和 3 出现在区间 [2, 3] 中
                            // 整数 7、8、9、10 出现在区间 [7, 10] 中
    countIntervals->add(5, 8);  // 将 [5, 8] 添加到区间集合中
    cout << countIntervals->count() << endl;    // 返回 8
                            // 整数 2 和 3 出现在区间 [2, 3] 中
                            // 整数 5 和 6 出现在区间 [5, 8] 中
                            // 整数 7 和 8 出现在区间 [5, 8] 和区间 [7, 10] 中
                            // 整数 9 和 10 出现在区间 [7, 10] 中
    
    return 0;
}