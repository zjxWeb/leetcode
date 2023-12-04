/**
 * @file 1038.cpp 从二叉搜索树到更大和树
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-04
 * @cite https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/description/
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// class Solution {
// public:
//     // int sum = 0;
//     TreeNode* bstToGst(TreeNode* root) {
        // // 逆序的中序遍历
        // if(root == nullptr) return nullptr;
        // if(root){
        //     bstToGst(root->right);
        //     sum += root->val;
        //     root->val = sum;
        //     bstToGst(root->left);
        // }
        // return root;
        
//     }
// };
// Morris 遍历
        /**
            1. 如果cur无左孩子，cur向右移动（cur=cur.right）
            2. 如果cur有左孩子，找到cur左子树上最右的节点，记为mostright
                1. 如果mostright的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
                2. 如果mostright的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
         */
class Solution {
public:
    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;

        while (node != nullptr) {
            if (node->right == nullptr) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            } else {
                TreeNode* succ = getSuccessor(node);
                if (succ->left == nullptr) {
                    succ->left = node;
                    node = node->right;
                } else {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    Solution s;
    s.bstToGst(root);
    return 0;
}