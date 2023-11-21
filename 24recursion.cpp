/**
 * @file 24.cpp 两两交换链表中的节点
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-21
 * @cite https://leetcode.cn/problems/swap-nodes-in-pairs/description/?envType=study-plan-v2&envId=top-100-liked
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        // 递归
        ListNode* node = head->next;
        head->next = swapPairs(node->next);
        node->next = head;
        return node;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *res = s.swapPairs(head);
    while (res!= nullptr){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}