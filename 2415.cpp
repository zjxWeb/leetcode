/**
 * @file 2415.cpp  反转二叉树的奇数层
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * @cite https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/
 * @copyright Copyright (c) 2023
 * 
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }
private:
    void dfs(TreeNode* root1, TreeNode* root2, bool isOdd)
    {
       if(root1 == nullptr) return;
       if(isOdd) swap(root1->val, root2->val);
       dfs(root1->left, root2->right,!isOdd);
       dfs(root1->right, root2->left,!isOdd);
    }

};

void order(TreeNode* cur, vector<vector<int>>& result, int depth)
{
    if (cur == nullptr) return;
    if (result.size() == depth) result.push_back(vector<int>());
    result[depth].push_back(cur->val);
    order(cur->left, result, depth + 1);
    order(cur->right, result, depth + 1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    int depth = 0;
    order(root, result, depth);
    return result;
}

// 层次遍历二叉树

int main(){
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);
    Solution s;
    TreeNode *res = s.reverseOddLevels(root);
    
    for (auto el : levelOrder(root)) {
        for (auto e : el) {
            cout << e << endl;
        }
    }
    
    return 0;
}
