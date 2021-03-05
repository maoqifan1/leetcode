/**
 * 从键盘输入m,n

在屏幕上按每行10个的格式输出m~n之间的全部素数。

请用函数判断一个数是否素数。

输入说明 :

两个整数m n

输出说明 :

[m,n]之间(包含m和n)的素数，每行10个，每个数后跟一个空格。


*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

bool judge_num(int x)
{ //判断是否为素数
    if (x == 1)
        return false;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void print_num(int a, int b)
{
    int n = 0;
    for (int i = a; i <= b; ++i)
    {
        if (judge_num(i))
        {
            cout << i << ' ';
            ++n;
            if (n % 10 == 0)
                cout << endl;
        } // 是素数
    }
}

int main()
{

    string str;
    int a, b;
    getline(cin, str);                               // 读取一行数据
    a = stoi(str.substr(0, str.find_first_of(' '))); // 获得两个数字
    b = stoi(str.substr(str.find_first_of(' ') + 1, str.length() - 1));
    print_num(a, b);
    return 0;
}