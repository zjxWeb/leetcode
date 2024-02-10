#include<iostream>
#include <vector>
#include <functional>

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
    bool isCousins(TreeNode* root, int x, int y) {
        // dfs
        int depth = 0;
        bool ans = false;// 记录是否是堂兄弟
        TreeNode * father = nullptr;
        function<bool(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode *cur, TreeNode *fa, int d) -> bool {
            if(cur == nullptr) return false;
            if(cur->val == x || cur->val == y){
                // 找到x/y
                if(depth){
                    ans = depth == d && father != fa;
                    return true; //表示 x 和 y 都找到
                }
                depth = d; // 没找到
                father = fa;
            }
            return dfs(cur->left, cur, d+1) || dfs(cur->right, cur, d+1);
        };
        dfs(root, nullptr, 1);
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    Solution s;
    cout << s.isCousins(root, 4, 3);
}