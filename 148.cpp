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
//自顶向下归并排序
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
        return sortList(head,nullptr);
    }
    // 将链表分成两半，并且使用归并进行排序
    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode * temp = dummy;
        ListNode* temp1 = l1,*temp2 = l2;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val <= temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1 != nullptr)temp->next = temp1;
        else if(temp2 != nullptr)temp->next = temp2;
        return dummy->next;
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