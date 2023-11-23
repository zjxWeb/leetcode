#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
class Solution {
public:
    int rob(TreeNode* root) {
        
    }
};

int main()
{
    Solution s;
    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->right = new TreeNode(3);
    t1->right->right = new TreeNode(1);
    cout << s.rob(t1) << endl;
}
