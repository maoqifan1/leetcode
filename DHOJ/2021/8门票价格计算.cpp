/**
 * 某旅游景点门票价格为每人5元。但团体可以优惠，分为以下情况： 

人数超过20，则所有人优惠10%； 

人数超过40，则所有人优惠15%； 

人数超过80，则所有人优惠20%； 

人数超过120，则所有人优惠30%。 

请跟据团体的人数，求出该团体的总门票价格。

输入说明 :

输入一个整数i（0≤i≤1,000），表示一个团体的总人数。在行首和行尾没有多余的空格。

输出说明 :

输出一个实数，即该团体需要支付的总票价，精确到小数点后2位。在行首和行尾不要输出多余的空格。
*/
#include <iostream>
using namespace std;

double price(int n)
{
    double p;
    if (n > 20 && n <= 40)
        p = n * 5 * 0.9;
    else if (n > 40 && n <= 80)
        p = n * 5 * 0.85;
    else if (n > 80 && n <= 120)
        p = n * 5 * 0.8;
    else if (n > 120)
        p = n * 5 * 0.7;
    else // 不打折的情况
        p = n * 5;
    return p;
}
int main(void)
{
    int n;
    cin >> n;
    double res = price(n);
    printf("%.2f", res);
}