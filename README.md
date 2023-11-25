# 每日一提，开始啦

## 49. 字母异位词分组

> 一般需要对特征进行归类的优先想到——哈希表

> 递归求解伪装回文路径
```c++
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
```