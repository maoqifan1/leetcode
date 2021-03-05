/**
 *尝试求从1+2+…+N这N个自然数的和。

输入说明 :

你的程序需要从标准输入设备（通常为键盘）中读入一个整数N（1 ≤ N < 10,000）；在行首和行尾没有多余的空格。在所有数据的前后，以及两组数据之间都没有多余的空行。

输出说明 :

对每组测试数据，你的程序需要向标准输出设备（通常为启动该程序的终端）输出对应的答案，其中仅有一个整数，即题目描述中的数列之和。在行首和行尾不要输出多余的空格。
 
*/
#include <iostream>
using namespace std;

inline int sum(int i)
{
    if (i == 1)
    {
        return 1;
    }
    else
    {
        return i + sum(i - 1);
    }
}
int main(void)
{
    int n, r;
    cin >> n;
    r = sum(n);
    cout << r;
}