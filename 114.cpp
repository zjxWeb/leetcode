/**
 * @file 114.cpp 二叉树展开为链表
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * @cite https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> res;
        preorderTraversal(root,res);
        int n = res.size();
        for (int i = 1; i < n; i++)
        {
            TreeNode* prev = res[i-1],*cur = res[i];
            prev->left = nullptr;
            prev->right = cur;
        }
        
    }
    void preorderTraversal(TreeNode* root,vector<TreeNode*>& res){
        if(root != nullptr) {
            res.push_back(root);
            preorderTraversal(root->left,res);
            preorderTraversal(root->right,res);
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    Solution s;
    s.flatten(root);
    return 0;
}