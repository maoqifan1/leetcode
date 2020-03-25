// 给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

// 示例 1：

// 输入: s1 = "abc", s2 = "bca"
// 输出: true
// 示例 2：

// 输入: s1 = "abc", s2 = "bad"
// 输出: false

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool CheckPermutation(string s1, string s2)
    {
        if (s1.size() != s2.size()) // 长度不同必不能重排
            return false;
        for (int i = 0; i < s1.size(); i++)
        {

            string ss1(1, s1[i]); //将字符型转为字符串
            string ss2(1, s2[i]);
            int idx1 = s1.find_first_of(ss2);  // 在s1串中找是否存在s2串中当前位置的字符
            int idx2 = s2.find_first_of(ss1);  // 在s2串中找是否存在s1串中当前位置的字符
            if (idx1 == s1.npos || idx2 == s2.npos)
            { //如果串1不包含串2的字符或者串2不包含串1的字符，则直接返回false
                return false;
            }
            else
            {
                s1.erase(idx1, 1); // 把这个位置的字符删掉
                s2.erase(idx2, 1); 
            }
        }
        return true;
    }
};