// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:

// 输入: "()"
// 输出: true
// 示例 2:

// 输入: "()[]{}"
// 输出: true
// 示例 3:

// 输入: "(]"
// 输出: false
// 示例 4:

// 输入: "([)]"
// 输出: false
// 示例 5:

// 输入: "{[]}"
// 输出: true

// 链接：https://leetcode-cn.com/problems/valid-parentheses

#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s == "") // 如果时空字符串也合法
            return true;
        if (s.size() == 1) // 只有一个字符肯定非法
            return false;
        stack<char> st;
        map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}}; // 映射括号
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) != mp.end()) // 查找mp是否映射了该符号
            {
                char top_ele = (st.size() == 0) ? '#' : st.top(); // 获取栈顶元素，若为空则随便设置一个字符
                if (top_ele != '#')                               // 栈不为空则弹出元素
                    st.pop();
                if (top_ele != mp.find(s[i])->second) // 如果这个元素被弹出的元素和mp对应映射的值不一样，则直接返回false
                    return false;
            }
            else
            {
                st.push(s[i]); //压入栈中
            }
        }
        return st.size() == 0; // 如果栈为空则表示合法
    }
};