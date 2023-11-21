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
        // 两数对应的值为n1 n2  进位值为 carry
        // sum = n1 + n2 + carry
        // 对应位置的值为sum % 10
        // 新的进位制为 sum / 10
        ListNode* head = nullptr,*tail = nullptr;
        int carry = 0;
        while(l1!= nullptr || l2!= nullptr){
            int n1 = l1 == nullptr? 0 : l1->val;
            int n2 = l2 == nullptr? 0 : l2->val;
            int sum = n1 + n2 + carry;
            if(!head){
                head = tail = new ListNode(sum % 10);
            }
            else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if(l1)l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry > 0) tail->next = new ListNode(carry);
        return head;
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