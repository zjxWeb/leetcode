/**
 * @file 466.cpp 统计重复个数
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/count-the-repetitions/description/
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


/*
我们预处理出以字符串 s2的每个位置 i 开始匹配一个完整的 s1 后，下一个位置 j 以及经过了多少个 s2，即 
d[i]=(cnt,j)，其中 cnt 表示匹配了多少个 s2，而 j 表示字符串 s2 的下一个位置。
接下来，我们初始化 j=0，然后循环 n1 次，每一次将 d[j][0] 加到答案中，然后更新 j=d[j][1]
最后得到的答案就是  个 s1 所能匹配的 s2 的个数，除以 n2n2n2 即可得到答案。
*/
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s1.length(),n = s2.length();
        vector<pair<int,int>>d;
        for(int i = 0; i < n; i++){
            int j = i;
            int cnt = 0;
            for(int k = 0;k < m; k++){
                if(s1[k] == s2[j]){
                    if(++j == n){
                        ++cnt;
                        j = 0;
                    }
                }
            }
            d.emplace_back(cnt,j);
        }
        int ans = 0;
        for (int j = 0; n1; --n1) {
            ans += d[j].first;
            j = d[j].second;
        }
        return ans / n2;
    }
};

int main(){
    Solution s;
    cout << s.getMaxRepetitions("acb", 4, "ab", 2) << endl;
    return 0;
}