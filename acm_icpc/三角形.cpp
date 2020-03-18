#include <iostream>
#include <algorithm>

using namespace std;

// 输入 棍子数 , 棍子组成的数组
void solve(int n, int *s)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int len = s[i] + s[j] + s[k];              // 周长
                int max_edge = max(s[i], max(s[j], s[k])); // 最大边的长度
                int res_edge = len - max_edge;             // 剩余边的长度和
                if (max_edge < res_edge)
                    res = len; // 可以组成三角形，则更新答案
            }
        }
    }
    printf("最大周长为:%d", res);
}
int main(void)
{
    int a[10] = {1, 3, 8, 11, 20, 35, 40, 22, 59};
    solve(9, a);
    return 0;
}