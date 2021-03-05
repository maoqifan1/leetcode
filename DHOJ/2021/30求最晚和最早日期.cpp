/**
 * 输入N个日期，每个以年、月、日的顺序读入，打印输出最晚的日期、最早的日期。


输入说明 :

你的程序需要从标准输入设备（通常为键盘）中读入多组测试数据。每组输入数据由多行组成。
每组测试数据的第一行输入一个整数N(0<N<20)，表示有N个日期。其后N行每行有三个整数Y(1≤Y≤2015)，M(1≤M≤12)，D(1≤D≤31)表示一个日期。


输出说明 :

对每组测试数据，你的程序需要向标准输出设备（通常为启动该程序的文本终端）输出两行，每行包括3个整数
，第一行为最晚日期，第二行为最早日期，整数之间以一个空格分隔，行首与行尾无空格，所有数据前后没有多余的空行，两组数据之间也没有多余的空行。


*/
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

typedef struct Date
{
    int y; // 年
    int m; // 月
    int d; // 日
    Date(int Y, int M, int D)
    {
        y = Y;
        m = M;
        d = D;
    }
} Date;
int main(void)
{
    stringstream ss;
    string input1, input2;
    int y, m, d;                 //年月日
    int i, N;                    //计数器
    vector<Date> vc;             // 存储结果
    while (getline(cin, input1)) // 日期数
    {
        if (input1.size() == 0) //输入为空，退出
            break;
        ss << input1; // 类型转换
        ss >> N;
        ss.clear(); //清空
        ss.str("");
        i = 0;
        while (((i++) < N) && getline(cin, input2)) // 具体日期
        {
            if (input2.size() == 0) // 输入为空，退出
                break;
            ss << input2.substr(0, input2.find_first_of(" ")); // 年
            ss >> y;
            ss.clear(); // 清空
            ss.str("");
            ss << input2.substr(input2.find_first_of(" "), input2.find_last_of(" ")); // 月
            ss >> m;
            ss.clear(); // 清空
            ss.str("");
            ss << input2.substr(input2.find_last_of(" "), input2.size()); // 日
            ss >> d;
            ss.clear(); // 清空
            ss.str("");
            vc.push_back(Date(y, m, d)); //存放结果
        }
    }
    int max_y, max_m, max_d, min_y, min_m, min_d;
    // 初始化最大最小日期
    max_y = min_y = vc[0].y;
    max_m = min_m = vc[0].m;
    max_d = min_d = vc[0].d;
    for (int i = 0; i < vc.size(); ++i)
    {
        if (vc[i].y > max_y) // 求最大
        {
            max_y = vc[i].y;
            max_m = vc[i].m;
            max_d = vc[i].d;
        }
        if (vc[i].y == max_y)
        {
            if (vc[i].m > max_m)
            {
                max_m = vc[i].m;
                max_d = vc[i].d;
            }
            if (vc[i].m == max_m)
            {
                if (vc[i].d > max_d)
                    max_d = vc[i].d;
            }
        }
        if (vc[i].y < min_y) // 求最小
        {
            min_y = vc[i].y;
            min_m = vc[i].m;
            min_d = vc[i].d;
        }
        if (vc[i].y == min_y)
        {
            if (vc[i].m < min_m)
            {
                min_m = vc[i].m;
                min_d = vc[i].d;
            }
            if (vc[i].m == min_m)
            {
                if (vc[i].d < min_d)
                    min_d = vc[i].d;
            }
        }
    }
    // 输出结果
    cout << max_y << " " << max_m << " " << max_d << endl;
    cout << min_y << " " << min_m << " " << min_d << endl;
}