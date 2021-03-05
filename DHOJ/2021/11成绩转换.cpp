/**
 * 输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：

90~100为A;

80~89为B;

70~79为C;

60~69为D;

0~59为E;

输入说明 :

输入一个整数。

输出说明 :

输出对应结果，占一行。如果输入数据不在0~100范围内，请输出一行：“Score is error!”。

注意：无多余空格。


*/
#include <iostream>
using namespace std;
int main(void)
{
    int input;
    cin >> input;
    if (0 <= input && input <= 59)
        printf("E");
    else if (60 <= input && input <= 69)
        printf("D");
    else if (70 <= input && input <= 79)
        printf("C");
    else if (80 <= input && input <= 89)
        printf("B");
    else if (90 <= input && input <= 100)
        printf("A");
    else
        printf("Score is error!");

    return 0;
}