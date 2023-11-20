/**
 * @file 234.cpp回文链表
 * @author zjxweb
 * @brief 
 * @version 0.1
 * @date 2023-11-19
 * @cite https://leetcode.cn/problems/palindrome-linked-list/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>

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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstNode = endNode(head);
        ListNode* secondNode = reverse(firstNode->next);
        // 判断是否是回文
        ListNode* p1 = head;
        ListNode* p2 = secondNode;
        bool res = true;
        while(res == true && p2!= nullptr)
        {
            if(p1->val!= p2->val)  res = false;;
            p1 = p1->next;
            p2 = p2->next;
        }
        firstNode->next = reverse(secondNode);
        return res;
    }
private:
    // 反转链表
    ListNode* reverse(ListNode* head){
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur!= nullptr){
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    //找到前半部分链表的尾节点
    ListNode* endNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
int main(){
    Solution s;
    ListNode *node = new ListNode(1);
    node->next  = new ListNode(2);
    node->next->next = new ListNode(2);
    node->next->next->next = new ListNode(1);
    cout << s.isPalindrome(node) << endl;
    return 0;
}