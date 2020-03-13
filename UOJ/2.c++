#include <iostream>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring> 
using namespace std;

/**
 * http://uoj.ac/problem/2 起床综合困难症
*/
int main()
{
    int n, m, k;
    string op; // 表示运算符
    op.resize(4);
    //第一行包含两个整数，依次为 n,m ,表示 drd 有 n 扇防御门，atm 的初始攻击力为 0 到 m 之间的整数。
    scanf("%d %d", &n, &m);
    bitset<32> bsm(m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", &op[0], &k); // 获得符号和将要位运算的数
        bitset<32> bsk(k);
        if (strcmp(op.c_str(), "AND") == 0)
            bsm &= bsk;
        else if (strcmp(op.c_str(), "OR") == 0)
            bsm |= bsk;
        else
            bsm ^= bsk;
    }
    printf("%lu", bsm.to_ulong());
    return 0;
}