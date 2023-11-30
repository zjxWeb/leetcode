/**
 * @file 124.cpp 二叉树中的最大路径和
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * @cite https://leetcode.cn/problems/binary-tree-maximum-path-sum/?envType=study-plan-v2&envId=top-100-liked
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

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxVal;
    }
private:
    int maxVal = INT_MIN;
    int maxSum(TreeNode* root){
        if(root == nullptr) return 0;
        int left = max(maxSum(root->left), 0);
        int right = max(maxSum(root->right), 0);
        // 左右子树的最大路径和
        int sum = root->val + left + right;
        // 左右子树的最大路径和 + 当前节点的路径和
        maxVal = max(maxVal, sum);
        return root->val + max(left,right);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    cout << s.maxPathSum(root) << endl;
    return 0;
}