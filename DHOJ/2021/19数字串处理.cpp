/**
 * 明明的爸爸经常对明明进行数学启蒙教育。有一天他和明明做了一个游戏，对一串数字进行处理。
 * 明明的爸爸首先给明明一串数字，在这串数字中有很多数字会连续重复出现很多次，爸爸就要求明明把其中连续重复出现次数最多的那个数字找出来。
 * 如果有很多个数字连续出现的次数相同，即重复出现次数最多的数字不止一个，那就要明明找出第一次出现该重复次数的那个数字。 
 * 例如有一串数字：2 2 2 1 1 1，其中2出现了3次，1也出现了3次，而明明要找出的那个数字是2，因为2是第一次重复出现3次的那个数字。 
 * 明明的爸爸现在已经设计好了很多组这样的数据，但是他不想自己来寻找，他想让你帮他写一个程序，找出出现次数最多的那个数字，
 * 然后他手中就有一份标准答案，可以用来检查明明到底做得对不对。 明明爸爸的问题可以归结为：给你一串数字，找出在这串数字中连续出现次数最多的那个数字；
 * 若有多个数字连续出现的次数相当，则找出第一次出现该次数的那个数字。

输入说明 :

你写的程序要求从标准输入设备中读入测试数据作为你所写程序的输入数据。
标准输入设备中有多组测试数据，每组测试数据有2行，测试数据的第一行有1个整数n（1<n<100），表示数字串中有几个数；
测试数据的第二行有n个数，数字串中的数字k，k（1 ≤k ≤100），每个数字之间用一个空格隔开。
每组测试数据与其后一组测试数据之间没有任何空行，第一组测试数据前面以及最后一组测试数据后面也都没有任何空行。

输出说明 :

对于每一组测试数据，你写的程序要求计算出一组相应的运算结果，并将这一组运算结果作为你所写程序的输出数据依次写入到标准输出设备中。
每组运算结果为两个整数：出现次数最多的那整数，以及它的出现次数。每组运算结果单独形成一行数据，其行首和行尾都没有任何空格，
每组运算结果与其后一组运算结果之间没有任何空行，第一组运算结果前面以及最后一组运算结果后面也都没有任何空行。 注：通常，显示屏为标准输出设备。
*/

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

/**
 * @return 返回所给数字串中连续重复出现次数最多的数字及其出现次数
 * @param number 所给数字串(每个数字用个空格隔开，数字取值于1-100之间)
 * @param n 数字串中所含数字的数量
*/
pair<string, int> clac_max(string number, int n)
{
    string str, res;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (number[i] != ' ') // 没遇到空格
        {
            str.push_back(number[i]);
        }
        // 遇到空格
        else
        {
            if (count == 0) //遇到新的数字，则将其设为最大
            {
                count = 1;
                res = str;
            }
            else
            {
                res == str ? count++ : count--;
            }
            str.erase(0, str.size()); // 清空
        }
    }
    return pair<string, int>(res, count);
}

int main(void)
{
    stringstream ss;
    string str1, str2;
    vector<pair<string, int> > vc;
    int n;

    while (true)
    {
        getline(cin, str1); // 获取第一行的数据
        if (str1.size() == 0)
            break;          // 若输入为空，结束读取
        getline(cin, str2); // 获取第二行的数据，为一个数字串
        ss << str1;
        ss >> n;    // n表示所给字符串中有多少个字符
        ss.clear(); // 清空stringstream
        ss.str("");
        vc.push_back(clac_max(str2, n)); // 获取结果
    }
    for (int i = 0; i < vc.size(); ++i) // 输出
    {
        cout << vc[i].first << " " << vc[i].second << endl;
    }
    return 0;
}