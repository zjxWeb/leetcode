#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <functional>
#include <queue>

using namespace std;

// N树的遍历
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class NTreeLevelOrder {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>res;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>level;
            for(int i = 0; i < n; i++){
                Node *cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for(auto el : cur->children){
                    q.push(el);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

// int main() {
//     // N树的层次遍历
//     NTreeLevelOrder nTree;
//     vector<int>root = {1,NULL,3,2,4,NULL,5,6};
//     Node *rootNode = new Node(root[0]);
//     for(auto el : root){
//         rootNode->children.push_back(new Node(el));
//     }
//     for(auto el : nTree.levelOrder(rootNode)){
//         for(auto el : el){
//             cout << el << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }




