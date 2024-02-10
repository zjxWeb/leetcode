#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 寻找树的公共祖先
        if(root == nullptr || p == root || q == root) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;
        if(left != nullptr && right == nullptr) return left;
        if(left == nullptr && right != nullptr) return right;
        else return nullptr;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    Solution sol;
    cout<<sol.lowestCommonAncestor(root,root->left,root->right)->val<<endl;
}