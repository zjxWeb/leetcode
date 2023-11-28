/**
 * @file 543.cpp 二叉树的直径
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * @cite https://leetcode.cn/problems/diameter-of-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <vector>
#include <algorithm>
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
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     if(root->left == nullptr && root->right == nullptr) return 1;
    //     vector<vector<int>>countLeft = levelOrder(root->left);
    //     vector<vector<int>>countRight = levelOrder(root->right);
    //     vector<int> maxsLeft,maxsRight;
    //     for(int i = 0;i < countLeft.size();i++){
    //         maxsLeft.push_back(countLeft[i].size());
    //     }
    //     for(int i = 0;i < countRight.size();i++){
    //         maxsRight.push_back(countRight[i].size());
    //     }
    //     return *max_element(maxsLeft.begin(),maxsLeft.end())+*max_element(maxsRight.begin(),maxsRight.end());
    // }
    // // 层次遍历(递归)
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     if(root == nullptr) return {};
    //     vector<vector<int>> res;
    //     int depth = 0;
    //     order(root,res,depth);
    //     return res;
    // }
    // void order(TreeNode* root,vector<vector<int>> &res,int depth){
    //     if(!root) return;
    //     if(res.size() <= depth) res.push_back(vector<int>());
    //     res[depth].push_back(root->val);
    //     order(root->left,res,depth+1);
    //     order(root->right,res,depth+1);
    // }

    int diameterOfBinaryTree(TreeNode* root) {
        //一条路径的长度为该路径经过的节点数减一，所以求直径（即求路径长度的最大值）等效于求路径经过节点数的最大值减一
        res = 1;
        dfs(root);
        return res-1;
    }
private:
    int res = 0;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res,left + right + 1);
        return max(left,right) + 1;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    cout << s.diameterOfBinaryTree(root) << endl;
    return 0;
}