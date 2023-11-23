/**
 * @file 25.cpp K 个一组翻转链表
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-21
 * @cite https://leetcode.cn/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <tuple>
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
    // dummy 虚拟头节点
    // pre 每次要反转列表的前一个节点 
    // tail 每次要反转列表的尾部节点（为了寻找k个节点）
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        while(head){
            ListNode* tail = pre;
            for(int i = 0; i < k; i++){
                tail = tail->next;
                if(!tail) return dummy->next;
            }
            // 记录下一个子链的起始位置
            ListNode* nextStart = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = reverseList(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = reverseList(head, tail);
            // 重新将子链接回原链表中
            pre->next = head;
            tail->next = nextStart;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
private:
    // 反转一个子列表
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *res = s.reverseKGroup(head,2);
    while (res!= nullptr){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}