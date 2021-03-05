/**
问题描述 :

编写程序计算并输出

s=sumk=1n (1/k) = 1+1/2+1/3+............+1/n 的值。

要求定义并调用函数total(n)计算1+1/2+1/3+......+1/n

注意：此题的main函数如下所示：

int main(){

 int n;

 scanf("%d",&n);

 printf("%.3f\n",total(n));

 return 0;

}

或者：

int main(){

 int n;

 cin>>n;

 cout<<fixed<<setprecision(3)<<total(n)<<endl;

 return 0;

}

输入说明 :

正整数n，表示前n项求和

输出说明 :

s，表示前n项的和

首尾无空格
*/
#include <iostream>
#include <math.h>
using namespace std;

/**
 * 求1-n之间数的倒数和
*/
double total(int n)
{
    double x = 0;
    for (int i = 1; i <= n; ++i)
    {
        x += pow(i, -1);
    }
    return x;
}
int main()
{

    int n;

    scanf("%d", &n);

    printf("%.3f\n", total(n));

    return 0;
}