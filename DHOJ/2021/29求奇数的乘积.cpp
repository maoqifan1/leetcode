/**
 * 给你n个整数，求他们中所有奇数的乘积。

输入说明 :

输入数据包含两行，第一行为一个数为n，表示第二行将输入n个整数。你可以假设这n个数据中必定至少存在一个奇数。



输出说明 :

输出一个整数。


*/
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main(void)
{
    stringstream ss;
    int n, sum, temp1;
    sum = 1;
    string input1, input2, str;
    while (getline(cin, input1))
    {
        if (input1.size() == 0) // 输入为空，退出
            break;
        ss << input1; // 类型转换
        ss >> n;
        ss.clear(); // 清空stringstream
        ss.str("");
        getline(cin, input2);
        if (input2.size() == 0)
            break;
    }
    for (int i = 0; i < input2.size(); ++i)
    {
        if (input2[i] == ' ') //空格跳过
        {
            ss << str; //类型转换
            ss >> temp1;
            ss.clear(); // 清空stringstream
            ss.str("");
            str.erase(0, str.size());         //清空字符串
            if (temp1 % 2 != 0 && temp1 != 0) //是奇数
                sum *= temp1;
        }
        else
        {
            str.push_back(input2[i]);
            if (i == input2.size() - 1) // 最后一个数且是奇数
            {
                ss << str; //类型转换
                ss >> temp1;
                ss.clear(); // 清空stringstream
                ss.str("");
                if (temp1 % 2 != 0 && temp1 != 0)
                    sum *= temp1;
            }
        }
    }
    cout << sum << endl;

    return 0;
}