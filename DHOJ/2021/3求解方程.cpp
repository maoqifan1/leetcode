/**
 * 编写程序：输入a、b后，输出一元一次方程2*a*x+3*b-5=0的解。

输入说明 :

整数a b

输出说明 :

x 保留1位小数

*/
#include <iostream>
using namespace std;
int main(void)
{
    double a, b;
    cin >> a >> b;
    double r;
    if (a == 0) // a = 0 无解
    {
        cout << "error";
    }
    else
    {
        r = (5 - 3 * b) / (2 * a);
        printf("%.1f", r);
    }
}