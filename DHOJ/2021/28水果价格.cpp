/**
 * 问题描述 :

一家水果店出售四种水果，每公斤价格的苹果（代码为a）1.5元，橘子（代码为o）1.4元，香蕉（代码为b）1.48元，菠萝（代码为p）1.08元。
编一个程序，使售货员只要在键盘上打入货品的代码及重量，计算机将显示货品名、单价、重量及总价。

输入说明 :

你的程序需要从标准输入设备（通常为键盘）中读入多组测试数据。

每组测试数据的第一行为一个整数m，表示有m件货品要被购买
。在接下来的m行中，每行输入两个值d，g。d表示货品的代码，g表示重量。两组数据之间没有多余的空行。

输出说明 :

对每组测试数据，你的程序需要向标准输出设备（通常为启动该程序的终端）依次输出一组对应的答案。
对应每组输入，输出货品名、单个总价及全部总价。具体格式参照样例输出:第一行apple前为7个空格，之后为2个空格，
其他水果名后都是1个空格，sum后没有空格；第二行price后有2个空格，其后关于价格的表示多为占7格2位小数且左对齐，
但其中pineapple为占10格2位小数且左对齐，注意sum的价格仍然占7格，如第一组样例中的54.60后还有2个空格；
第三行weight后有1个空格，其后的数据与第二行一致。每两组数据之间有一个空行，最后一组测试数据之后没有空行。


*/
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
    const double ap = 1.5;
    const double op = 1.4;
    const double bp = 1.48;
    const double pp = 1.08;

    stringstream ss;
    string str1, str2, temp2, res;           // res记录结果
    vector<vector<pair<double, double> > > vc; // 存储结果
    char temp1;
    int m, i;
    double temp_weight, apple_price, apple_weight, orange_price, orange_weight, banana_price, banana_weight,
        pineapple_price, pineapple_weight, sum_price, sum_weight;
    while (getline(cin, str1))
    {
        // str1读取有多少件货品要被购买
        if (str1.size() == 0)
            break;  // 未输入，则退出读取
        ss << str1; // 类型转换
        ss >> m;
        ss.clear(); // 清空stringstream
        ss.str("");
        //初始化
        temp_weight = apple_price = apple_weight = orange_price =
            orange_weight = banana_price = banana_weight = pineapple_price = pineapple_weight = sum_price = sum_weight = 0;
        i = 0; 
        vector<pair<double, double> > vcc;       // 定义次级容器
        while ((i++) < m && getline(cin, str2)) // str2 读取货品以及货品的质量
        {
            if (str2.size() == 0) // 未输入，则退出
                break;

            temp1 = str2[0];                                          //获得水果种类
            temp2 = str2.substr(str2.find(" ") + 1, str2.size() - 1); // 获得水果的重量
            ss << temp2;
            ss >> temp_weight; // 获得公斤
            ss.clear();        // 清空
            ss.str("");
            switch (temp1)
            {
            case 'a': // 苹果
                apple_weight += temp_weight;
                break;
            case 'o': // 橙子
                orange_weight += temp_weight;
                break;
            case 'b': // 香蕉
                banana_weight += temp_weight;
                break;
            case 'p': // 菠萝
                pineapple_weight += temp_weight;
                break;
            }
        }
        // 计算价格
        apple_price += apple_weight * ap;
        banana_price += banana_weight * bp;
        orange_price += orange_weight * op;
        pineapple_price += pineapple_weight * pp;
        // 计算总价格
        sum_price = apple_price + banana_price + orange_price + pineapple_price;
        // 计算总质量
        sum_weight = apple_weight + orange_weight + banana_weight + pineapple_weight;
        vcc.push_back(pair<double, double>(apple_price, apple_weight)); // 存储结果
        vcc.push_back(pair<double, double>(orange_price, orange_weight));
        vcc.push_back(pair<double, double>(banana_price, banana_weight));
        vcc.push_back(pair<double, double>(pineapple_price, pineapple_weight));
        vcc.push_back(pair<double, double>(sum_price, sum_weight));
        vc.push_back(vcc);
        // 排版
    }
    // 输出结果
    for (int i = 0; i < vc.size(); ++i)
    {
        printf("       apple  orange banana pineapple sum\n");
        printf("price  %-7.2f%-7.2f%-7.2f%-10.2f%-7.2f\n", vc[i][0].first, vc[i][1].first, vc[i][2].first, vc[i][3].first, vc[i][4].first);
        printf("weight %-7.2f%-7.2f%-7.2f%-10.2f%-7.2f\n", vc[i][0].second, vc[i][1].second, vc[i][2].second, vc[i][3].second, vc[i][4].second);
        printf("\n");
    }

    return 0;
}