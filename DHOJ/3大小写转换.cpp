/**
 * 问题描述 :

从键盘输入一个大写字母，改用小写字母输出。

输入说明 :

一个大写英文字符

输出说明 :

对应的小写英文字符。

输入范例 :

A
输出范例 :

a
*/
#include <iostream>
using namespace std;

/**
 * 将大写字母转换为小写字母
 * @param alpha 待转换的大写字母
*/
void transform(char alpha)
{
    // 这里 -0 可以将字母转为整型变量
    int i = alpha - 0 + 32;
    alpha = i;
    cout << alpha;
}
int main(void)
{
    char c;
    cout << "请输入需要转换的大写字母" << endl;
    cin >> c;
    transform(c);
    return 0;
}