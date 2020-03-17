// 给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。
// 假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

// 注意：每次拼写时，chars 中的每个字母都只能用一次。
// 返回词汇表 words 中你掌握的所有单词的 长度之和。

// 输入：words = ["cat","bt","hat","tree"], chars = "atach"
// 输出：6
// 解释：
// 可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。

// 输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
// 输出：10
// 解释：
// 可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int count = 0;
        bool flag = false;                     // 标记
        string c_chars(chars);                 // 构造c_chars保存chars
        for (int i = 0; i < words.size(); i++) // 迭代单词表
        {
            if (c_chars.size() < words[i].size()) //如果单词的字母多于可选字母，则跳过这个单词
                continue;
            for (int j = 0; j < words[i].size(); j++) // 迭代可选择的字母
            {
                int index = c_chars.find(words[i][j]);
                if (index != c_chars.npos) // 能找到这个字母
                {
                    flag = true;
                    c_chars.erase(index, 1); // 从c_chars()删除这个字母
                }
                else
                {
                    flag = false; // 不能找到,意味着不能组成这个单词
                    break;        //跳出这次循环
                }
            }
            if (flag) // 如果符合则计数加1
                count += words[i].size();
            c_chars.assign(chars); // 把chars的值在再次赋值给c_chars
        }
        return count;
    }
};