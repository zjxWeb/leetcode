/**
 * @file 1457.cpp二叉树中的伪回文路径
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-25
 * @cite https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/
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
    int pseudoPalindromicPaths (TreeNode* root) {
    // 所有数字出现偶数次——回文字符
    // 只有一个数字出现奇数次，其余都是出现偶数次
    // 用bit记录出现数字出现的次数的奇偶性，XOR运算 ：偶数次结果为0 ，奇数次结果为1
    return dfs(root, 0);
    }
    // 递归求解伪装回文路径
    int dfs(TreeNode* root, int bit) {
        if (!root) return 0;
        // 是使用异或运算来修改一个整数的特定位。
        bit ^= 1 << (root->val - 1); // 记录出现数字出现的次数的奇偶性
        cout << root->val << " " << bit << endl;
        int res = dfs(root->left, bit) + dfs(root->right, bit); // 递归求解左右子树的结果
        if (!root->left &&!root->right) {
            return (bit & (bit - 1))? 0 : 1; // 1个数字出现奇数次，其余都是偶数次
        }
        return res;
    }

};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    Solution s;
    cout << s.pseudoPalindromicPaths(root) << endl;
}