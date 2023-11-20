/**
 * @file 2.cpp 两数相加
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-20
 * @cite https://leetcode.cn/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

    }
};

int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode *res = s.addTwoNumbers(l1,l2);
    while (res!= nullptr){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}