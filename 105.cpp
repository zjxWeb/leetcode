/**
 * @file 105.cpp 从前序与中序遍历序列构造二叉树
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * @copyright Copyright (c) 2023
 * @cite https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-100-liked
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 1. 先从前序遍历序列中取出根节点
        // 2. 在中序遍历序列中找到根节点的位置，并将左子树和右子树的序列分别取出
        // 3. 递归调用buildTree函数，分别对左子树和右子树进行递归构建
        // 4. 将左子树和右子树构建成树节点，并将根节点的左右指针指向左右子树
        // 前序遍历取出根节点
        if(preorder.size() && inorder.size())
        {
            TreeNode * newNode = new TreeNode(preorder[0]);
            int index = 0;
            // 在中序遍历中找到根节点的位置
            for(int i = 0; i < inorder.size(); i++){
                if(inorder[i] == preorder[0]){
                    index = i;
                    break;
                }
            }
            preorder.erase(preorder.begin());
            vector<int> left(inorder.begin(), inorder.begin() + index);
            newNode->left = buildTree(preorder, left);
            vector<int> right(inorder.begin() + index + 1, inorder.end());
            newNode->right = buildTree(preorder, right);
            return newNode;
        }
        return nullptr;
    }
};

int main(){
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = s.buildTree(preorder, inorder);
    cout << root->val << endl;
    return 0;
}
