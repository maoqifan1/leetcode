/**
 * 有一种自然数，它的各位数字之和能被17整除。这个数的后继数（即这个数加1）的各位数字之和也能被17整除。求所有自然数中，从小到大第n个这样的数。

输入说明 :

你的程序需要从标准输入设备（通常为键盘）中读入多组测试数据。每组输入数据占一行，其中仅有一个整数n（1≤n≤10）。
在行首和行尾没有多余的空格。所有数据前后没有多余的空行，两组数据之间也没有多余的空行。

输出说明 :

对每组测试数据，你的程序需要向标准输出设备（通常为启动该程序的终端）依次输出一组对应的答案。
每组答案占一行，每行中仅有一个整数，即题目描述中的第n个数。在行首和行尾不要输出多余的空格。在所有数据的前后，以及两组数据之间不要输出多余的空行。

*/

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

// 工具函数，找到满足各位数字之和能被17整除的第n个数，且满足这个定义
int find(int n)
{
    return 0;
}

int main(void)
{
    stringstream ss;
    string input;
    int num;
    vector<int> vc;
    while (getline(cin, input))
    {
        if (input.size() == 0) // 输入为0 ，退出循环
            break;
        ss << input; // 类型转换
        ss >> num;
        ss.str(""); // 清空
        ss.clear();
    }
    return 0;
}