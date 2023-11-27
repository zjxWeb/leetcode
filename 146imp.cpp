/**
 * @file 146. LRU 缓存  哈希表 + 双向链表
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * @cite https://leetcode.cn/problems/lru-cache/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct DLinkedNode  {
    int key;
    int val;
    DLinkedNode  *prev;
    DLinkedNode  *next;
    DLinkedNode () : key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode (int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    // 哈希表 + 双向链表
public:
    // 构造函数，初始化成员变量
    LRUCache(int capacity): capacity(capacity), size(0) {
        head = new DLinkedNode ();
        tail = new DLinkedNode ();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key))  return -1;
        // 如果key存在的时候
        DLinkedNode  * node = cache[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            // 不存在的情况
            DLinkedNode  * node = new DLinkedNode (key, value);
            cache[key] = node;
            addHead(node);
            size++;
            if(size > capacity){
                // 超出容量，删除尾部节点
                DLinkedNode  * removed  = removeTail();
                cache.erase(removed->key);
                delete removed;// 防止内存泄漏
                size--;
            }
        }
        else{
            // 存在的情况
            DLinkedNode  * node = cache[key];
            node->val = value;
            moveToHead(node);
        }
    }
private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode  *head;
    DLinkedNode  *tail;
    int capacity;
    int size;

    // 添加节点(头插法)
    void addHead(DLinkedNode  *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    //删除节点（）
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 移动到头节点
    void moveToHead(DLinkedNode  *node) {
        removeNode(node);
        addHead(node);
    }

    // 删除尾部节点，返回新的链表，
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

int main(){
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl;    // 返回 3
    cout << lRUCache->get(4) << endl;    // 返回 4
    return 0;
}