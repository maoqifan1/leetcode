// 题目
/*
   n只蚂蚁以每秒1cm的速度在常委Lcm的杆子上爬行。当蚂蚁爬到杆子的端点时就会掉落。
   由于杆子太细，两只蚂蚁相遇时，他们不能交错通过，只能各自反向爬回去。对于每只蚂蚁，
   我们知道它距离杆子左端的距离xi,但不知道它当前的朝向。请计算所有蚂蚁落下杆子所需的最短时间和最长时间。
*/
#include <iostream>
using namespace std;
void solve(int L, int N, int *p) // 杆子长度  蚂蚁数 每只蚂蚁距离杆子的长度 的数组
{
    // 计算最短时间
    int min_t = 0;
    for (int i = 0; i < N; i++)
    {
        min_t = max(min_t, min(p[i], L - p[i]));
    }
    // 计算最长时间
    int max_t;
    for (int i = 0; i < N; i++)
    {
        max_t = max(max_t, max(p[i], L - p[i]));
    }

    printf("最短时间 : %d\n最长时间 : %d", min_t, max_t);
}
int main()
{
    int p[3] = {2, 6, 7};
    solve(10, 3, p);
}