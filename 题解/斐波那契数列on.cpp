#include <iostream>
using namespace std;

int fab(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int pre = 1;
    int next = 2;
    int result = 0;
    for (int i = 3; i < n + 1; i++) // 求前n项和
    {
        result = pre + next;
        pre = next;
        next = result;
    }
    return result;
}
int main()
{
    unsigned long long result = 0;
    // 求前50项的和
    for (int i = 1; i <= 50; i++)
    {
        result += fab(i);
    }
    printf("前50项的和为 : %lld", result);
}