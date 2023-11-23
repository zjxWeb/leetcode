/**
 * @file 92.cpp 反转链表 II
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-22
 * @cite https://leetcode.cn/problems/reverse-linked-list-ii/description/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 添加一个哨兵
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 0;i < left -1;i++) pre = pre->next;
        ListNode* cur = pre->next;
        ListNode* nxt = nullptr;
        for(int i = 0;i < right - left;i++){
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        } 
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int left = 2;
    int right = 4;
    Solution sol;
    ListNode* res = sol.reverseBetween(head, left, right);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}