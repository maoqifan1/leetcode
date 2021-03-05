/**
 *
问题描述 :

判断一个数是不是素数

输入说明 :

第一行为N

下面N行，每行一个数字n



输出说明 :

判断n是不是素数，是就输出yes，否则输出no
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

// 工具函数，判断输入字符串的整数形式是否为素数
string judge(string input)
{
    stringstream ss;
    int num;
    ss << input; // 类型转换
    ss >> num;
    for (int i = 2; i < num; ++i)
    {
        if (num % i == 0)
            return "no";
    }
    return "yes";
}

int main(void)
{
    stringstream ss;
    string input1, input2;
    int num, i;
    num = i = 0;
    vector<string> vc;
    while (getline(cin, input1))
    {
        if (input1.size() == 0) // 输入为空，退出
            break;
        ss << input1; // 类型转换
        ss >> num;
        ss.str(""); // 清空stringstream
        ss.clear();
        while (i++ < num && getline(cin, input2))
        {
            vc.push_back(judge(input2));
        }
    }
    for (int i = 0; i < vc.size(); ++i)
    {
        cout << vc[i] << endl;
    }
}