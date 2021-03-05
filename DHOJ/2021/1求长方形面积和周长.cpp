/**
 * 求一个长方形的面积S及周长P。面积的公式为S = a × b，周长的公式P=2*(a+b)，其中a代表长方形的长，b代表长方形的宽。

输入说明 :

你的程序需要从标准输入设备（通常为键盘）中读入两个整数：一个整数a（0 ≤a < 10000），代表长方形的长；一个整数b（0 ≤ b < 10000），代表长方形的宽；在a和b之间有一个空格；在行首和行尾没有多余的空格。

输出说明 :

你的程序需要向标准输出文件（通常为启动该程序的终端）输出对应的答案。答案占一行，其中包含两个整数，即长方行的面积和周长，中间以一个空格分隔。在行首和行尾不要输出多余的空格。
*/
#include <iostream>
using namespace std;
int main(void)
{
    int a, b, s, p;
    cin >> a >> b;
    s = a * b;
    p = 2 * (a + b);
    cout << s << " " << p;
    return 0;
}