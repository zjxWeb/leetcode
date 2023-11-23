/**
 * @file 148.cpp排序链表
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-23
 * @cite https://leetcode.cn/problems/sort-list/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 */

#include <iostream>
// #include <set>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 借助multiset来实现，编译器可以通过，lettcode不能通过
        // if(!head) return nullptr;
        // multiset<int> set;
        // ListNode* p = head;
        // while(head){
        //     set.insert(head->val);
        //     head = head->next;
        // }
        // for(auto &el : set){
        //     p->val = el;
        //     p = p->next;
        // }
        // return p;

        //自顶向下归并排序
        
    }
};

int main(){
    
    Solution s;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    s.sortList(head);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}