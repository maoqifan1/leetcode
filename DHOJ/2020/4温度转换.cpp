/**
 * 问题描述 :

从键盘输入一个摄氏温度，要求转换成华氏温度输出。摄氏温度转换为华氏温度的公式为（其中c表示摄氏温度，f表示华氏温度）： f=(9/5)*c+32

输入说明 :

输入一个摄氏温度

输出说明 :

输出对应的华氏温度。注意，输出结果保留两位小数，小数点后第三位四舍五入到小数点后第二位,但小数点后总共输出6位(即最后需要输出4个0)。

输入范例 :

26.67
输出范例 :

80.010000


*/
#include <iostream>
#include <cstdio>
using namespace std;
/**
 * @param centigree 需要转换的摄氏温度
*/
void convert(double centigree)
{
    double f = (9.0 / 5.0) * centigree + 32;
    printf("%.2f0000", f);
}
int main(void)
{
    double c=0.0;
    cout << "请输入需要转换的摄氏温度" << endl;
    cin>>c;
    convert(26.67);
}