/**
 * 问题描述 :

数学一直是明明很喜欢的一门学科，不但上课认真听讲，而且还自己钻研。有一次，老师在课上讲了一种特殊的四位整数，这种整数有两个特性：

第一，它是某一个自然数的平方；

第二，它的千位数字与十位数字之和等于百位数字与个位数字之积。

然后老师就举了一个例子：1156，1156是34的平方，且1156的千位数字1加上十位数字5等于百位数字1乘以个数数字6，即1+5=1*6。

然后老师告诉同学，这是最小的一个符合以上两个特性的四位整数，接着老师就留下了作业，
要让同学们回家后尽量多的找出符合这两个特性的特殊四位数。明明回家后，就开始找了起来，1157、1158、1159、……、3136，直到到了3136（3136=56*56，3+3=1*6），
明明才找到了第二个这样的特殊四位数。明明觉得这样找下去不是办法，后面还有好几千个数字要一个一个试下来，这样一定无法在睡觉前完成。
于是明明就求助于你，帮他写一个程序，从小到大求出所有的这样的特殊四位数，然后当明明想要第几个这样的特殊四位数时，你就能够很快的告诉他。
 如果把上述所有的特殊四位数按从小到大的顺序排列后记为S1，S2，…，Sn，…，即排在第1个位置上的特殊四位数记为S1，
 排在第2个位置上的特殊四位数记为S2，…，排在第n个位置上的特殊四位数记为Sn，那么明明的问题可以归结为：假如一个特殊四位数排在第n个位置上，
 那么这个特殊四位数Sn等于多少呢？

输入说明 :

你写的程序要求从标准输入设备中读入测试数据作为你所写程序的输入数据。
标准输入设备中有多组测试数据，每组测试数据仅占一行，每行仅有一个正整数n（n不大于特殊四位数的个数）
，表示要求第n个特殊四位数Sn。每组测试数据与其后一组测试数据之间没有任何空行，第一组测试数据前面以及最后一组测试数据后面也都没有任何空行。

输出说明 :

对于每一组测试数据，你写的程序要求计算出一组相应的运算结果，
并将这一组运算结果作为你所写程序的输出数据依次写入到标准输出设备中。
每组运算结果为一个正整数，表示与输入数据n相对应的那个特殊四位数Sn，每组运算结果单独形成一行数据，
其行首和行尾都没有任何空格，每组运算结果与其后一组运算结果之间没有任何空行，第一组运算结果前面以及最后一组运算结果后面也都没有任何空行。 注：通常，显示屏为标准输出设备。

*/
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

void find_num(int *&a)
{
    int *b = new int;
    string s;
    int j = 0; // 自增用
    // 找四位数中符合要求的数
    for (int i = 1000; i < 10000; i++)
    {
        float divide = sqrt((float)i); //开根
        s = to_string(i);              // 转换字符串

        b[0] = s[0] - '0'; // 个位
        b[1] = s[1] - '0'; // 十位
        b[2] = s[2] - '0'; // 百位
        b[3] = s[3] - '0'; // 千位

        if (divide == (int)divide && (b[3] * b[1] == b[0] + b[2]))
        {               // 满足定义，开方是自然数，千位和十位之和等于百位和个位之积
            a[j++] = i; // 保存到数组里
        }
    }
    delete b;
}

int main(void)
{
    string str;
    vector<int> vec;
    int num;
    int *c = new int;
    find_num(c);
    while (getline(cin, str))
    {
        if (str.length() == 0)
        {
            break; // 输入为空停止
        }
        num = stoi(str); // 将字符串转换为整数
        vec.push_back(c[num - 1]);
    }
    // 输出
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec.at(i) << endl;
    }
    delete c;
    return 0;
}