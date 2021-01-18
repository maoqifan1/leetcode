/**
 * 问题描述 :

从键盘输入一个整数，编程判断它的奇偶性。

输入说明 :

输入一个数字n

输出说明 :

输出n是奇数还是偶数。比如，输入数字5，则输出“5 is odd”；输入数字6，则输出“6 is even”

输入范例 :

5
输出范例 :

5 is odd
*/
#include <iostream>
#include <cstdio>
using namespace std;

/**
 * 判断一个数是奇数还是偶数
 * @param x 为待判断的整数
*/
void is_even_or_odd(int x)
{
    printf("%d is %s", x, x % 2 == 0 ? "even" : "odd");
}
int main(void)
{
    int i = 0;
    cout << "请输入一个数" << endl;
    cin >> i;
    is_even_or_odd(i);
    return 0;
}