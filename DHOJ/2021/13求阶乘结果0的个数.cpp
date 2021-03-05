/**
 * 编写一个程序，求出N！的末尾含有多少个0。

提示：在乘积中，末尾有多少个0，主要看各乘数的素数因子中有多少个2和5，每一个2和5的结合将给末尾贡献一个0。而乘数中因子2的个数远多于因子5的个数，因此，就计算各乘数中因子5的个数即可。

输入说明 :

你的数据需要从标准输入设备（通常为键盘）中读入多组测试数据。每组输入数据由一行组成，每行由一个正整数N组成，N小于等于100000，在行首和行尾没有多余的空格。

输出说明 :

对每组测试数据，你的程序需要向标准输出文件（通常为启动该程序的文本终端）依次输出一组对应的答案。所有数据前后不要输出多余的空行，
两组数据之间也不要输出多余的空行。每组输出数据由一行组成，每行由一个整数组成，在行首和行尾不要输出多余的空格。

*/
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

// 求n的阶乘中，因子k的个数
int count(int n, int k)
{
    int num = 0;
    while (n)
    {
        num += n / k;
        n /= k;
    }
    return num;
}
int main(void)
{
    vector<int> vt;
    stringstream ss;
    string input;
    int datum;
    while (getline(cin, input)) // 逐行读取数据
    {
        if (input.size() == 0) // 读入数据为0
            break;
        ss << input; // 数据类型转换
        ss >> datum;
        ss.clear();
        ss.str(""); // 清空stringstream
        vt.push_back(count(datum, 5));
    }
    for (int i = 0; i < vt.size(); ++i)
        cout << vt[i] << endl;
    return 0;
}