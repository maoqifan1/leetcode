// 字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。
// 若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

// 示例1:

//  输入："aabcccccaaa"
//  输出："a2b1c5a3"
// 示例2:

//  输入："abbccd"
//  输出："abbccd"
//  解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
public:
    string compressString(string S)
    {
        string compress; // 存储压缩后的字符串
        int j = 1;
        for (int i = 0; i < S.size(); i++)
        {
            if (i != S.size() - 1 && S[i] == S[i + 1]) // 如果后一个字符串与当前相同，则计数+1，并且跳过本次循环
            {
                j++;
                continue;
            } // 否则就将该字符加入，并在后面加上对应的计数，然后计数变为1
            compress.push_back(S[i]);
            compress.append(to_string(j));
            j = 1;
        }
        return compress.size() < S.size() ? compress : S; // 如果压缩后的字符串大于原字符串则返回原字符串
    }
};
int main()
{
    Solution *s = new Solution();
    cout << s->compressString("aaabbbccc");
}