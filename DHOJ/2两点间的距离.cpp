/**
 * 问题描述 :

输入两点坐标（X1,Y1）,（X2,Y2）,计算并输出两点间的距离。

输入说明 :

输入数据由4个实数组成，分别表示x1,y1,x2,y2,数据之间用空格隔开。

输出说明 :

输出结果，保留两位小数。

输入范例 :

3 4 -10 0
输出范例 :

13.60
*/

#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
/**
 * 输出两点间的距离
 * @param x1 第一个点横坐标
 * @param y1 第一个点纵坐标
 * @param x2 第二个点横坐标
 * @param y2 第二个点纵坐标
*/
void get_distance(int x1, int y1, int x2, int y2)
{
    double distance = pow(pow(x1-x2,2)+pow(y1-y2,2),0.5);
    // 也可以使用sqrt，这里略
    printf("%.2f",distance);
}
int main(void)
{
    int x1,x2,x3,x4;
    cout<<"输入四个点的坐标并用空格隔开"<<endl;
    cin>>x1>>x2>>x3>>x4;
    get_distance(x1,x2,x3,x4);
    return  0;
}