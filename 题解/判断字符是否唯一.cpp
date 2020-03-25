#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// 实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

// 示例 1：

// 输入: s = "leetcode"
// 输出: false
// 示例 2：

// 输入: s = "abc"
// 输出: true

class Solution
{
public:
    bool isUnique(string astr)
    {
        bool flag = true;
        for (int i = 0; i < astr.size(); i++)
        {
            string s(1, astr[i]);              // 将字符转为字符串
            if (astr.find(s) != astr.rfind(s)) // 看该字符在字符串中出现第一次的索引和最后一次的索引是否一致，不一致，表示该字符不唯一，直接设置falg为fakse然后跳出循环
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};