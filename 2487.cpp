/**
 * @file 2487.cpp从链表中移除节点
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-03
 *  
 * @copyright Copyright (c) 2024
 * 
 */
ListNode* removeNodes(ListNode* head) {
        if(head == nullptr) return nullptr;
        head->next = removeNodes( head->next);
        if(head->next != nullptr && head->val < head->next->val) return head->next;
        else return head;
    }