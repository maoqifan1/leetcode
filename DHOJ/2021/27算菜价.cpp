/**
 * 问题描述 :

妈妈每天都要出去买菜，但是回来后，兜里的钱也懒得数一数，到底花了多少钱真是一笔糊涂帐。现在好了，作为好儿子（女儿）的你可以给她用程序算一下了，呵呵。

输入说明 :

输入含有一些数据组，第一行第一个数是测试组数，第二行第一个数据是菜种数，每组数据包括菜种（字串），
数量（计量单位不论，一律为double型数）和单价（double型数，表示人民币元数），因此，每组数据的菜价就是数量乘上单价啊。菜种、数量和单价之间都有空格隔开的。

注意样例输入应是如下：

1
3
青菜 1  2
罗卜 2  1.5
鸡腿 2  4.2

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

int main(void)
{
    stringstream ss;
    string input1, input2, input3;
    int test_num, v_num;                // 测试组数，菜种数
    int i, j;                           // 计数器
    double v_count, v_price, sum_price; // 单个菜的数量和单价和总价
    string v_name;                      // 菜名
    vector<double> vc;                  // 存储结果
    while (getline(cin, input1))        // 测试数据数
    {
        if (input1.size() == 0)
            break;    // 输入为空，退出
        ss << input1; // 类型转换
        ss >> test_num;
        ss.clear(); // 清空stringstream
        ss.str("");
        i = 0;                                             // 初始化
        while (((i++) < test_num) && getline(cin, input2)) // 菜种数
        {
            if (input2.size() == 0) // 输入为空，退出
                break;
            ss << input2; // 类型转换
            ss >> v_num;
            ss.clear(); // 清空stringstream
            ss.str("");
            j = 0;                                          // 初始化
            sum_price = 0;                                  // 初始化总菜价为0
            while (((j++) < v_num) && getline(cin, input3)) // 菜
            {
                if (input3.size() == 0) // 输入为空，退出
                    break;
                v_name = input3.substr(0, input3.find_first_of(" "));         // 获得菜名
                ss << input3.substr(input3.find_last_of(" "), input3.size()); // 菜的单价
                ss >> v_price;                                                //类型转换
                ss.clear();                                                   // 清空
                ss.str("");
                ss << input3.substr(input3.find_first_of(" "), input3.find_last_of(" ")); // 菜的数量
                ss >> v_count;                                                            //类型转换
                ss.clear();
                ss.str(""); // 清空
                sum_price += v_count * v_price;
            }
            vc.push_back(sum_price); // 存入结果
        }
    }
    for (int k = 0; k < vc.size(); k++)
    {
        printf("%.1f\n", vc[k]);
    }
    return 0;
}