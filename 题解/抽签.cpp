#include <iostream>
#include <cstdio>
using namespace std;
int main(void)
{
    const int MAX_N = 50;
    int n, m, k[MAX_N]; // n 表示卡片数，总共抽4次 抽到和为m时你赢 , k 存储纸片
    puts("请输入卡片的数量,以及卡片上的数字和是何值是你赢");
    scanf("%d %d", &n, &m);
    puts("请依次输入卡片的值");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }
    // 表示是否找到和为m
    bool flag = false;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            for (int c = 0; c < n; c++)
            {
                for (int d = 0; d < n; d++)
                {
                    if (k[a] + k[b] + k[c] + k[d] == m)
                        flag = true; // 找到了
                }
            }
        }
    }
    if (flag)
        puts("你赢了");
    else
        puts("你输了");
    return 0;
}