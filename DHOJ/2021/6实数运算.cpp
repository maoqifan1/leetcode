/**
 * 输入两个实数，求它们的和，差，积，商。

输入说明 :

输入数据由两行组成：第一行为两个实数a、b，它们以空格分隔，在行首和行尾没有多余的空格；第二行为运算符号'+'、'-'、'*'、'/'之一，在行首和行尾没有多余的空格。

输出说明 :

输出运算结果(保留一位小数)，行首和行尾没有多余的空格，当除数为0时输出'Wrong!'。


*/
#include <iostream>
using namespace std;
double op(double a, double b, char op) //进行运算操作
{
    double result;
    switch (op)
    {
    case '+':
        result = a + b;
        break;

    case '-':
        result = a - b;
        break;

    case '*':
        result = a * b;
        break;
    case '/':
        if (b == 0) // 除数位0 特殊处理
            result = -1;
        else
            result = a / b;
        break;
    default:
        break;
    }
    return result;
}
int main(void)
{
    double a, b, result;
    char ex; // 运算符
    cin >> a >> b;
    cin >> ex;
    result = op(a, b, ex);
    if (result == -1)
        printf("Wrong!");
    else
        printf("%.1f", result); // 保留一位小数
}