/**
 * 输入两个时间A和B，分别都由3个整数组成，分别表示时分秒，比如，假设A为34 45 56，就表示A所表示的时间是34小时 45分钟 56秒。

输出A+B即两个时间相加后的结果。



输入说明 :

输入数据由6个整数AH,AM,AS,BH,BM,BS组成，分别表示时间A和B所对应的时分秒。题目保证所有的数据合法。

输出说明 :

输出A+B，输出结果也由时分秒三部分组成，同时也要满足时间的规则（即：分和秒的取值范围在0~59），输出仅占一行，整数之间以一个空格分隔，行首与行尾无多余空格。


*/
#include <iostream>
using namespace std;

int main(void)
{
    int AH, AM, AS, BH, BM, BS, rh, rm, rs, i, j;
    cin >> AH >> AM >> AS >> BH >> BM >> BS; // 输入
    rs = AS + BS;
    i = rs / 60;
    rm += AM + BM + i; //判断是否进位
    j = rm / 60;
    rh = AH + BH + j; // 判断是否进位
    cout << rh << " " << rm - j * 60 << " " << rs - i * 60;
}