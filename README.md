# 每日一提，开始啦

## c++中的auto、const auto&

+ 先介绍一下auto、const
+ 在块作用域、命名作用域、循环初始化语句等等 中声明变量时，关键词auto用作类型指定符。

+  `const`:修饰符

+ 接下来我们细细分析一下：

### （1）auto

> `auto即 for(auto x:range)` 这样会拷贝一份range元素，而不会改变range中元素；

   

> 但是！（重点) 使用`for(auto x:vector<bool>)`时得到一个proxy class,操作时会改变vector<bool>本身元素。应用：`for(bool x:vector<bool>)`

### （2）`auto&`

> 当需要修改range中元素，用`for(auto& x:range)`

  

> 当vector<bool>返回临时对象，使用`auto&`会编译错误，临时对象不能绑在`non-const l-value reference （左值引用）`需使用**auto&&**,初始化右值时也可捕获

### （3）`const auto&`  

> 当只想读取range中元素时，使用`const auto&`,如：`for(const auto&x:range),`它不会进行拷贝，也不会修改range  

### （4）`const auto`

> 当需要拷贝元素，但不可修改拷贝出来的值时，使用 `for(const auto x:range)`，避免拷贝开销                                                    

### 整理下：                                                                                                                          

> + **想要拷贝**元素：`for(auto x:range)`

> + **想要修改**元素 : `for(auto &&x:range)`

> + **想要只读**元素：for(const auto& x:range) 


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

