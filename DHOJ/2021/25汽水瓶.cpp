/**

问题描述 :

有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。
小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，
方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，
喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，
喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？

输入说明 :

输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。

输出说明 :

对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

*/
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

int main(void)
{
    stringstream ss;
    string input;
    vector<int> vc;
    int bot, emp_bot; // bot表示可以喝到的汽水数,emp_bot表示空瓶
    while (getline(cin, input))
    {
        if (input == "0")
            break;   // 输入0时，结束读取
        bot = 0;     // 初始化为0
        ss << input; // 类型转换
        ss >> emp_bot;
        ss.clear();
        ss.str("");
        while (emp_bot >= 2)
        {
            if (emp_bot == 2) // 只在第一次循环中起作用
            {
                bot += 1;
                break;
            }
            if (emp_bot == 3)
            {
                bot += 1;
                break;
            }
            while (emp_bot >= 3)
            {
                bot += emp_bot / 3;
                emp_bot /= 3;
                emp_bot += bot;
            }
            if (emp_bot == 2)
            {
                bot += 1;
                emp_bot = 0;
            }
            cout << bot << endl;
        }
        vc.push_back(bot);
    }
    for (int i = 0; i < vc.size(); ++i)
        cout << vc[i] << endl;
    return 0;
}