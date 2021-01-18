/**
 * 问题描述 :

根据输入的半径值，计算球的体积。

球体积的计算公式为：

4/3 * PI * r3

其中PI的取值为：3.1415927

输入说明 :

输入数据为一个实数，表示球的半径，半径范围为[0,1000]。

输出说明 :

输出对应的球的体积，计算结果保留三位小数。不要输出多余空格。

输入范例 :

1.1
输出范例 :

5.575
*/
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415927

using namespace std;

/** 输出球的体积，保留小数点后三位
 * @param radius 为球的半径
*/
void get_sphere_cube(double radius)
{
    double cube = (4 / 3) * PI * pow(radius, 3);
    printf("%.3f", cube);
}
int main(void)
{
    int r = 0;
    cout << "请输入球的半径" << endl;
    cin >> r;
    get_sphere_cube(r);
    return 0;
}