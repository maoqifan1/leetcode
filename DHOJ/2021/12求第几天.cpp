/**
 * 按年、月、日的顺序读入一个日期，输出该日期是这一年中的第几天。

输入说明 :

输入数据为三个正整数y 、m、d，分别表示年、月、日，整数之间以空格分隔，在行首和行尾没有多余的空格。

输出说明 :

输出一个整数，表示输入的日期是这一年中的第几天，在行首和行尾没有多余的空格。


*/
#include <iostream>
using namespace std;

/**
 * @description 用于判断当前年，当前月共有多少天，返回天数
 * @return int
 * @param y 年
 * @param m 月
*/
int judge_day(int y, int m)
{
    int d;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) //闰年,2月有29天
    {
        if (m == 2)

            d = 29;

        else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)

            d = 31;
        else
            d = 30;
    }
    else // 平年
    {
        if (m == 2)

            d = 28;

        else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)

            d = 31;
        else
            d = 30;
    }
    return d;
}

/**
 * @param y 年
 * @param m 月
 * @param d 日
*/
int get_day(int y, int m, int d)
{
    int days = 0; // 用于累加天数
    for (int i = 1; i < m; ++i)
    {
        days += judge_day(y, i);
    }
    days += d; // 加上最后一个月的天数
    return days;
}
int main(void)
{
    int y, m, d;
    cin >> y >> m >> d;
    int result = get_day(y, m, d); // 调用函数
    cout << result;
    return 0;
}