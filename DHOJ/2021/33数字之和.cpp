/**
 * 输入一个正整数，求这个正整数的各位数字之和。

输入说明 :

你的程序需要从标准输入设备（通常为键盘）中读入多组测试数据。每组测试数据为正整数，每行一个N，N小于20000。

输出说明 :

对每组测试数据，你的程序需要向标准输出文件（通常为启动该程序的文本终端）依次输出一组对应的答案：输出为它的各位数字之和，所有数据前后没有多余的空行，两组数据之间也没有多余的空行。
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

// 工具函数，对传入的字符串的每一位数字进行求和
int sum(string s)
{
    stringstream ss;
    int sum,num;
    sum = num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ss<<s[i];
        ss>>num;
        ss.str("");
        ss.clear();
        sum += num; // 将字符转为整型
    }
    return sum;
}

int main(void)
{
    string input; // 输入数据
    vector<int> vec;
    int input_num; // 输入数据的整型形式
    while (getline(cin, input))
    {
        if (input.length() == 0) // 输入为空，退出循环
            break;
        vec.push_back(sum(input));
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << endl;
    }
    return 0;
}