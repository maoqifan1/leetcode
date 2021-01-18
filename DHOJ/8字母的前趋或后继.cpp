/**
 * 问题描述 :

输入一个小写英文字母。如果这个字母是英文字母表的前13个字母中的一个(m字母及m以前的字母)，则输出它的后一个字母；否则输出它的前一个字母。 比如输入a，则输出b，输入z，则输出y。
输入说明 :

输入一个小写字母，不需要考虑其它字符。在行首和行尾没有多余的空格。
输出说明 :

对应输入的小写字母，输出它对应的前趋或后继字母。行首和行尾不要输出多余的空格。
输入范例 :

a
输出范例 :

b
*/
#include <iostream>
using namespace std;
/**
 * @param c 代处理的的小写字母
*/
char pre_or_succ(char c)
{
    int x = c - 0;           // 获得字符对应的ascii码
    if (x >= 97 || x <= 110) // 前13个小写字母中的一个
        x += 1;
    else if (x > 110 || x <= 123) // 后13个小写字母中的一个
        x -= 1;
    c = x; // 将ascii转为对应的字母
    return c;
}
int main()
{
    char c;
    cout << "请输入26个小写字母中的一个" << endl;
    cin >> c;
    char res = pre_or_succ(c);
    cout << res;
    return 0;
}