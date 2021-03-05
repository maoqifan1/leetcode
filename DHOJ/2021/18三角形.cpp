/**
 * “明明，你会用1到9这九个数字组成一个三角形吗？”明明的爸爸问明明。
 * 明明被问的很莫名其妙，不明白他爸爸在说什么，于是就问道：“用1到9组成三角形？？？”
 * “是的，我的要求很简单，给你2个数，一个数作为这个三角形的开始，另一个数决定这个三角形的大小。例如我给你5和6这两个数，你就要组成如下的一个三角形：

5
6 7
8 9 1
2 3 4 5
6 7 8 9 1
2 3 4 5 6 7

明白了吗？”
明明观察了许久，终于看出了门道来，说道：“就是说给我2个数，例如5和6，那我就要从5这个数开始构建一个三角形。
第一行为一个数字，第二行为2个数字，以此类推，直到第六行的六个数字，且三角形中的数字都是1到9在循环重复，是这样吗？”
“明明真聪明，就是这样。”明明爸爸高兴的说道。于是明明的爸爸给了明明很多组这样的数字，明明也构建出了很多个不同的三角形。

你能像明明那样，写一个程序来构建上面的三角形吗？

输入说明 :

你写的程序要求从标准输入设备中读入测试数据作为你所写程序的输入数据。
标准输入设备中有多组测试数据，每组测试数据仅有一行，每行有两个整数s和n（1≤s≤9，1≤n≤80），其中s表示位于三角形的最顶端的数字，n表示三角形由几行数字组成。
每组测试数据与其后一组测试数据之间没有任何空行，第一组测试数据前面以及最后一组测试数据后面也都没有任何空行。



输出说明 :

对于每一组测试数据，你写的程序要求计算出一组相应的运算结果，并将每组运算结果作为你所写程序的输出数据依次写入到标准输出设备中。
每组运算结果为构建出来的三角形，三角形中的同一行的数字两两之间用一个空格隔开。每组运算结果与其后一组运算结果之间有一个空行，最后一组运算结果后面没有空行。

注：通常，显示屏为标准输出设备。


*/
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

/**
 * @param x 起始数字
 * @param y 所构建三角形的高
*/
string print_triangle(int x, int y)
{
    string str, res;
    stringstream ss;
    for (int i = 1; i <= y; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (x > 9) // 超过9时，还原到1
                x = 1;
            ss << x;
            ss >> res;
            ss.clear();
            ss.str("");
            str.append(res);
            if (j != i) // 最后一列不加空格
                str.append(" ");
            ++x; // x 自增
        }
        str.append("\n"); // 换行
    }
    return str;
}

int main(void)
{
    stringstream ss;
    string str;
    vector<string> vc;
    int i, j;
    while (getline(cin, str)) // 逐行读取输入
    {
        if (str.size() == 0) // 输入为0 ，退出
            break;
        ss << str[0]; // 第一个数
        ss >> i;
        ss.clear(); // 清空stringstream
        ss.str("");
        ss << str.substr(str.find(" ") + 1, str.size() - 1); // 第二个数
        ss >> j;
        ss.clear(); // 清空
        ss.str("");
        vc.push_back(print_triangle(i, j));
    }
    for (int i = 0; i < vc.size(); ++i) // 输出
    {
        cout << vc[i];
        if (i != vc.size() - 1) // 最后一行不换行
            cout << endl;
    }
    return 0;
}