/**
 * 编写程序求方程ax2+bx+c=0的根，a、b、c的值由键盘输入，假设b2-4ac>0

输入说明 :

3个整数a b c，以一个空格分隔

输出说明 :

两个根，大数在前，小数在后

输出时保留两位小数。


*/
#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    double r1, r2;
    r1 = (-b + pow(pow(b, 2) - 4 * a * c, 0.5)) / (2 * a); // 第一个根
    r2 = (-b - pow(pow(b, 2) - 4 * a * c, 0.5)) / (2 * a);//第二个根
    if (r1 > r2)
        printf("%.2f %.2f", r1, r2);
    else
        printf("%.2f %.2f", r2, r1);
}