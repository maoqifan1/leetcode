/**
 * 问题描述 :

有一天，明明在做数学作业的时候，发现了一组很有趣的数字。
例如1、11、121、1331等等。他发现这些数字都是左右对称的，即不管你把这些数字从左读到右还是从右读到左，读出来的数字都是一样的。
于是明明就把这个发现告诉了他爸爸。明明的爸爸是一名数学专家，他当然对这种类型的数字早有研究，他对明明说：“这些是回文数，它是一种特殊的数字现象
，即这些数字的左右两边是对称的。例如：121左右两边对称，1331左右也是对称的。”明明觉得这很有趣，接着问他爸爸还有什么和这类回文数有关的好玩的东西，
明明的爸爸于是就教了明明一种方法，这种方法是从任意一个整数出发，经过某种计算，就可以得到一个回文数。 
这个方法如下： 例如首先给你一个数19，然后把它的最低位与最高位交换（如果还有更多位，则次低位与次高位交换......），
得到它的逆序数91，然后两数相加，即19+91=110，我们得到110，因为110不是回文数，因此我们继续上面的步骤，110+11=121
，现在我们就得到了一个回文数121。通过这种方法，我们就可以求得一个与某一个整数有关的回文数。 明明很聪明，很快就掌握了这个方法，但是他也发现了一个问题，
就是有时候计算一个回文数，需要重复很多次以上的步骤，这使得明明很烦恼。于是他就求助于你，请你帮他写一个程序，通过程序来完成以上求回文数的过程。 


 明明的问题可以归结为：给你一个整数，通过上面叙述的求回文数的方法，求出回文数，并输出求解过程。输入数据保证该回文数小于2^31

输入说明 :

你写的程序要求从标准输入设备中读入测试数据作为你所写程序的输入数据。标准输入设备中有多组测试数据，
每组测试数据仅占一行，每行有一个整数n（10≤n≤10000），即要求回文数的那个整数。当n=0时，表示输入结束。
每组测试数据与其后一组测试数据之间没有任何空行，第一组测试数据前面以及最后一组测试数据后面也都没有任何空行。

输出说明 :

对于每一组测试数据，你写的程序要求计算出一组相应的运算结果，
并将这一组运算结果作为你所写程序的输出数据依次写入到标准输出设备中。每组运算结果为一行或多行的回文数求解过程
，直到求出回文数为止。每行的格式如下a+b=c，其中a是原来的数，b是a的交换后的那个数，c是a+b的结果，详细格式请参考输出样例。
每组运算结果与其后一组运算结果之间没有任何空行，第一组运算结果前面以及最后一组运算结果后面也都没有任何空行。 注：通常，显示屏为标准输出设备。
*/
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// 工具函数，判断传入的数是否为回文数
bool judge(int num)
{
    string s;
    bool flag = true;
    stringstream ss;
    ss << num; // 类型转换
    ss >> s;
    ss.str(""); // 清空
    ss.clear();
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != s[s.length() - i - 1])
        { // 判断是否对称
            flag = false;
            break;
        }
    }
    return flag;
}

int main(void)
{
    stringstream ss;
    vector<string> vec;
    string input, rev_input;              // 输入数据,翻转后的输入数据
    int input_num, rev_input_num, result; // 输入数据的整型形式,翻转后的数据的整型形式
    result = input_num = rev_input_num = 0;
    while (getline(cin, input))
    {                     // 接收输入
        if (input == "0") // 若输入为0,则退出循环
        {
            break;
        }
        rev_input = input;
        reverse(rev_input.begin(), rev_input.end());
        ss << input; // 类型转换,将字符串转换为整型
        ss >> input_num;
        ss.str(""); // 清空stringstream
        ss.clear();
        ss << rev_input;
        ss >> rev_input_num; // 类型转换
        ss.str("");
        ss.clear(); // 清空stringstream
        result = input_num + rev_input_num;
        vec.push_back(to_string(input_num) + "+" + to_string(rev_input_num) + "=" + to_string(result)); // 将结果存入vector中
        while (!judge(result))                                                                          // 当不是回文数时，执行循环
        {
            input_num = result;
            rev_input = to_string(result);               // 赋值
            reverse(rev_input.begin(), rev_input.end()); // 翻转
            ss << rev_input;
            ss >> rev_input_num;
            ss.str("");
            ss.clear();
            result = input_num + rev_input_num;
            vec.push_back(to_string(input_num) + "+" + to_string(rev_input_num) + "=" + to_string(result)); // 将结果存入vector中
        }
    }
    for (int i = 0; i < vec.size(); ++i)
    { // 输出结果
        cout << vec[i] << endl;
    }
    return 0;
}