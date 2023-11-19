/**
 * @file 160.cpp
 * @author zjxweb
 * @brief  相交链表
 * @version 0.1
 * @date 2023-11-19
 * @cite https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 */

#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr) {
            if (visited.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

int main() {
    Solution s;
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    headA->next->next->next = new ListNode(2);
    headA->next->next->next->next = new ListNode(4);
    ListNode *headB = new ListNode(3);
    headB->next = new ListNode(2);
    headB->next->next = new ListNode(4);
    // 遍历链表
    ListNode *p = s.getIntersectionNode(headA, headB);
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}
