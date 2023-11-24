/**
 * @file 23.cpp 合并 K 个升序链表
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-24
 * @cite  https://leetcode.cn/problems/merge-k-sorted-lists/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* res = nullptr;
        if(n == 0)return nullptr;
        if(n == 1)return lists[0];
        for(int i = 0;i < n - 1;i++) res = merge(res,lists[i]);
        return res;
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode * temp = dummy;
        ListNode* temp1 = l1,*temp2 = l2;
        if ((!l1) || (!l2)) return l1 ? l1 : l2;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val < temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        temp->next = (temp1 ? temp1 : temp2);
        return dummy->next;
    }
};


int main(){
    Solution s;
    vector<ListNode*> lists = {
        // new ListNode(1,new ListNode(4,new ListNode(5))),
        // new ListNode(1,new ListNode(3,new ListNode(4))),
        // new ListNode(2,new ListNode(6))
        new ListNode(2),
        new ListNode(),
        new ListNode(-1)
    };
    ListNode* ans = s.mergeKLists(lists);
    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}

