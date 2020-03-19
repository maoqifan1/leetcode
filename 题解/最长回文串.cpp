// 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

// 注意:
// 假设字符串的长度不会超过 1010。

// 示例 1:
// 输入:
// "abccccdd"
// 输出:
// 7

// 解释:
// 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int char_map[128] = {0}; //字符哈希
        int max_length = 0;      //回文串除中心点外的长度
        int flag = 0;            //是否有中心点
        for (int i = 0; i < s.length(); i++)
        {
            char_map[s[i]]++; //利用整数的数组下标实现字符哈希,统计字符个数
        }
        for (int i = 0; i < 128; i++)
        {
            if (char_map[i] % 2 == 0) // 如果该字符数为偶数，则表示该字符一定可以构成回文串
                max_length += char_map[i];
            else // 如果该字符数为奇数，减-1并计入整数，并且减掉的字符可以成为中心点
            {
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }
        return flag + max_length; // 返回最大回文串的长度
    }
};
int main()
{
    Solution *s = new Solution();
    int length = s->longestPalindrome("adbsaudhanwdqdpoqjroinjdfbahbasvasdvyd");
    printf("最大回文串的长度为:%d", length);
}