/**
 * @file 230.cpp 二叉搜索树中第K小的元素
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * @cite https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
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
    int kthSmallest(TreeNode* root, int k) {
        // 找到第k个最小元素
        if(root == nullptr) return -1;
        inorder(root);
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
private:
    // 遍历树，将节点的值存到vector中，然后返回第k个最小值
    vector<int>nums;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(5);
    cout << s.kthSmallest(root, 2) << endl;
    return 0;
}
