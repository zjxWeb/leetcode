/**
 * @file 138.cpp随机链表的复制
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-23
 * @cite https://leetcode.cn/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*,Node*>res;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(!res.count(head)){
            Node* newNode = new Node(head->val);
            res[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }
        return res[head];
    }
};
