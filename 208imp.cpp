/**
 * @file 208.cpp 实现 Trie (前缀树)
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-05
 * @cite https://leetcode.cn/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

// 其中count表示以当前单词结尾的单词数量。

// prefix表示以该处节点之前的字符串为前缀的单词数量。

/**
 * for (int i = 0; i < 26; i++) {
    char ch = 'a' + i;
    if (parentNode->next[i] == NULL) {
        说明父结点的后一个字母不可为 ch
    } else {
        说明父结点的后一个字母可以是 ch
    }
}
 */

class Trie
{
private:
    bool isend; // 判断是否是单词结尾
    Trie* next[26]; // 映射表
public:
    Trie()
    {
        this->isend = false;
        memset(next, 0, sizeof(next));
    }

    /**
     * @brief 
     * 这个操作和构建链表很像。首先从根结点的子结点开始与 word 第一个字符进行匹配，一直匹配到前缀链上没有对应的字符，
     * 这时开始不断开辟新的结点，直到插入完 word 的最后一个字符，同时还要将最后一个结点isEnd = true;，表示它是一个单词的末尾。
     * @param word 
     * @return ** void 
     */
    void insert(string word)
    {
        Trie* node = this;
        for(auto el : word)
        {
            if(node->next[el - 'a'] == NULL) node->next[el - 'a'] = new Trie();
            node = node->next[el - 'a'];
        }
        node->isend = true;
    }

    /**
     * @brief 
     * 从根结点的子结点开始，一直向下匹配即可，如果出现结点值为空就返回 false，如果匹配到了最后一个字符，那我们只需判断 node->isEnd即可。
     * @param word 
     * @return true 
     * @return false 
     */
    bool search(string word)
    {
        Trie* node = this;
        for(auto el : word){
            node = node->next[el - 'a'];
            if(node == NULL) return false;
        }
        return node->isend;
    }

    /**
     * @brief 
     * 和 search 操作类似，只是不需要判断最后一个字符结点的isEnd，因为既然能匹配到最后一个字符，那后面一定有单词是以它为前缀的。
     * @param prefix 
     * @return true 
     * @return false 
     */
    bool startsWith(string prefix)
    {
        Trie* node = this;
        for(auto el : prefix){
            node = node->next[el - 'a'];
            if(node == NULL) return false;
        }
        return true;
    }
};

int main()
{
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // 返回 True
    cout << trie->search("app") << endl;     // 返回 False
    cout << trie->startsWith("app") << endl; // 返回 True
    trie->insert("app");
    cout << trie->search("app") << endl; // 返回 True
}