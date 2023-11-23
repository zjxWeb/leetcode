/**
 * @file 1410.cpp HTML 实体解析器
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-23
 * @cite https://leetcode.cn/problems/html-entity-parser/description/
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class Solution {
// public:
//     using EntityChar = pair <string, char>;

//     vector <EntityChar> entityList;

//     string entityParser(string text) {
//         entityList = vector({
//             (EntityChar){"&quot;", '"'},
//             (EntityChar){"&apos;", '\''},
//             (EntityChar){"&amp;", '&'},
//             (EntityChar){"&gt;", '>'},
//             (EntityChar){"&lt;", '<'},
//             (EntityChar){"&frasl;", '/'}
//         });

//         string r = "";
//         for (int pos = 0; pos < text.size(); ) {
//             bool isEntity = false;
//             if (text[pos] == '&') {
//                 for (const auto &[e, c]: entityList) {
//                     if (text.substr(pos, e.size()) == e) {
//                         r.push_back(c);
//                         pos += e.size();
//                         isEntity = true;
//                         break;
//                     }
//                 }
//             }
//             if (!isEntity) {
//                 r.push_back(text[pos++]);
//                 continue;
//             }
//         }
//         return r;
//     }
// };
#define REPLACE(STRING, CHAR)\
{\
    static constexpr string_view sv = #STRING;\
    if (i + sv.size() <= s && string_view(&c, sv.size()) == sv) {\
        ans += CHAR;\
        i += sv.size();\
        continue;\
    }\
}

class Solution {
public:
    string entityParser(string text) {
        //size_t是C/C++标准库提供的数据类型，用于表示指针或数组的大小。
        const size_t s = text.size();
        string ans;
        ans.reserve(s);
        for (size_t i = 0; i < s;) {
            const char& c = text[i];
            if (c == '&') {
                REPLACE(&quot;, '\"')
                REPLACE(&apos;, '\'')
                REPLACE(&amp;, '&')
                REPLACE(&gt;, '>')
                REPLACE(&lt;, '<')
                REPLACE(&frasl;, '/')
            }
            ans += c;
            ++i;
        }
        return ans;
    }
};
int main() {
    Solution sol;
    string text = "&amp; is an HTML entity but &ambassador; is not.";
    // "x > y && x < y is always false"
    cout << sol.entityParser(text) << endl;
    return 0;
}
