/**
 * @file 987.cpp 二叉树的垂序遍历
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-13
 * https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/description/?envType=daily-question&envId=2024-02-13
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include <map>

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//DFS 的同时，用一个哈希表（或者有序字典）来记录这些数据。
//哈希表的 key 是 col，哈希表的 value 是一个列表，
//列表中保存 (row,val)二元组。

class Solution {
public:
    map<int,vector<pair<int,int>>>groups;
    void dfs(TreeNode *node,int row,int col){
        if(node == nullptr) return;
        // col 相同的分到一组
        groups[col].emplace_back(row,node->val);
        dfs(node->left,row+1,col-1);
        dfs(node->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>> res;
        for(auto &[_,g]: groups){
            sort(g.begin(),g.end());
            vector<int> temp;
            for(auto & [row,val]: g){
                temp.push_back(val);
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    Solution s;
    for(auto & el : s.verticalTraversal(root)){
        for(auto & e : el){
            cout << e << " ";
        }
    }
    return 0;
}