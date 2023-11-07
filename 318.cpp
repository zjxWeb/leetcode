/**
 * @file 318. 最大单词长度乘积
 * @author zjxweb (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 * 给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。

    示例 1：
    输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
    输出：16 
    解释：这两个单词为 "abcw", "xtfn"。
    示例 2：
    输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
    输出：4 
    解释：这两个单词为 "ab", "cd"。
    示例 3：
    输入：words = ["a","aa","aaa","aaaa"]
    输出：0 
    解释：不存在这样的两个单词。
    

    提示：
    2 <= words.length <= 1000
    1 <= words[i].length <= 1000
    words[i] 仅包含小写字母
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// masks[i] |= 1 << (word[j] - 'a'); - 这一行代码是核心。它执行以下操作：

// word[j] - 'a'：计算字符word[j]与字母'a'之间的偏移，将其转化为整数。
// 例如，如果word[j]是小写字母'a'，则计算结果为0；如果是'b'，则结果为1，依此类推。

// 1 << (word[j] - 'a')：将1左移上述偏移值的位数，以在二进制中标记出该字母的位置。
// 例如，如果word[j]是'b'，那么1 << 1 将产生二进制00000010。

// masks[i] |= ...：将上述计算结果与masks[i]进行按位或运算，以便将字符串word中的所有字母的二进制标记组合在一起。
// 这样，masks[i]的二进制表示将包含该字符串中所有不同的字母位置信息。


// 两个字母位掩码做  ”|“  ---- 表示两个字母和在一起
// 两个字母位掩码做  ”&“  ---- 可以判断是否有公共子串
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>mask(n);
        for (int i = 0; i < n; i++)
        {
            string str = words[i];
            int wordLenth = str.size();
            for (int j = 0; j < wordLenth; j++)
            {
                //合并字母位掩码
                mask[i] |=  1 << (str[j] - 'a');
            }   
        }
        int maxRes = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if((mask[i] & mask[j]) == 0){
                    maxRes = max(maxRes,int(words[i].size()*words[j].size()));
                }
            }
            
        }
        return maxRes;
        
    }
};

int main(){
    Solution s;
    vector<string>words ={"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << s.maxProduct(words) << endl;
    return 0;
}