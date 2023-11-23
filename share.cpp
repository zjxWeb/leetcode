#include<iostream>
#include<map>
#include<memory>
#include<string>
using namespace std;

// int main()
// {
//     shared_ptr<int> sp = make_shared<int>(1);
//     map<int, shared_ptr<int>> mp;
//     cout << "befor use_count: "<<sp.use_count()<<endl;
//     mp[1] = sp;
//     cout << "after use_count: "<<sp.use_count()<<endl;
// }

static char findFirstChar3(char *pString)
         {
             string str = ""; //用字符串保存读取的字符流,，方便后面求字符串大小
             map<char, int> hashTable;  //声明map实现哈希表，存放对应字符出现的个数（　字符：出现次数）
             int ch;
             while(*pString != '\0')
             {
                 str += *pString;
                 hashTable[*pString++]++;  // hashTable['c'] = 1;
             }
             for(int i = 0; i < str.size(); i++)
             {
                 if(hashTable[str[i]] == 1)
                 {
                     return str[i];
                 }
             }
             return '\0';
         }
int main()
{
    char * pString = "AABCA";
    for(auto el : pString)
    {
        cout << findFirstChar3(el) << endl;
    }
}