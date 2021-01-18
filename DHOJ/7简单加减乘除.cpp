/**
 * 问题描述 :

从键盘输入两个实数到变量a和b中，然后输入一个数字代表进行的运算，该数字为1则代表对a和b做加法，2代表减法，3代表乘法，4代表除法。

如果输入1 3 4，表示进行1/3的操作，结果为0.333333。输出时，保留两位小数，因此输出0.33。

注：可直接使用printf的控制格式实现保留两位小数的目的。

输入说明 :

输入两个实数，再输入一个1到4的整数，三个数字之间以空格分隔。

输出说明 :

输出计算结果，保留两位小数。如果做除法，但分母是0，则输出“error!”。输出时，行首与行尾均无空格。

输入范例 :

1 3 1
输出范例 :

4.00
 * 
*/
#include <iostream>
using namespace std;
/**
 *@param a 为参加运算的第一个数
 *@param b 为参加运算的第二个数 
*/
void op(double a, double b, int c)
{
    switch (c)
    {
    case 1:
        printf("%.2f", a + b);
        break;
    case 2:
        printf("%.2f", a - b);
        break;
    case 3:
        printf("%.2f", a * b);
        break;
    case 4:
        if (b == 0) // 分母为0
        {
            printf("error!");
        }
        else
        {
            printf("%.2f", a / b);
        }
        break;
    default:
        break;
    }
}
int main(void)
{
    op(1, 0, 4);
}