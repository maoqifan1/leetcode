/**
 * 寻找怪数：有一种奇怪的自然数，它的比其本身小的所有因子之和等于它本身，例如：6＝1＋2＋3，其中1、2、3都是6的因子，编程找出整数N之内的所有怪数。

输入说明 :

输入一个整数N(10<=N≤10000)，在行首和行尾没有多余的空格。

输出说明 :

输出N之内(<=N)的所有怪数，每一行输出一个整数。（注：若N中有3个怪数，你则需要输出三行，每行一个怪数。）所有数据前后没有多余的空格，中间也没有多余的空行。
*/

#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int factors;
    for (int i = 1; i <= N; ++i)
    {
        factors = 0;
        for (int j = 1; j < i; ++j)
        {
            if (i % j == 0) // 是因子
            {
                factors += j;
            }
        }
        if (factors == i)
        {
            cout << i << endl;
        }
    }
}