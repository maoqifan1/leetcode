/**
 * 问题描述 :

N的阶乘写作N!表示小于等于N的所有正整数的乘积。阶乘会很快的变大，如13!就必须用32位整数类型来存储，70！即使用浮点数也存不下了。
你的任务是找到阶乘最后面的非零位。举个例子,5!=1*2*3*4*5=120所以5!的最后面的非零位是2，7！=1*2*3*4*5*6*7=5040，所以最后面的非零位是4。

输入说明 :

一个不大于1000的整数N。

输出说明 :

共一行，输出N!最后面的非零位。
*/

#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

long factor(long m)
{
    if (m == 0)
    {
        return 1;
    }
    long x = 1;
    for (int i = 1; i <= m; i++)
    {
        x *= i;
        while (x % 10 == 0)
        {
            x /= 10;
        }
        x %= 100000;
    }
    return x;
}

int main(void)
{
    int N;
    cin >> N;
    long n = factor(N);
    if (n > 0)
        cout << n % 10 << endl;
    return 0;
}