/**
凑零钱
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
输入: coins = [1, 2, 5], amount = 11，输出: 3 解释: 11 = 5 + 5 + 1
输入: coins = [2], amount = 3，输出: -1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_VALUE 0x3f3f3f3f
using namespace std;
class Soultion
{
public:
    int coinChange(int amount, vector<int> &coins)
    {
        int max;
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        for (int i = 0; i < coins.size(); i++)
        {
            int sub_min = coinChange(amount - coins[i], coins);
            if (sub_min = -1)
                continue;
            max = min(MAX_VALUE, sub_min + 1);
        }
        if (max = MAX_VALUE)
            return -1;
        return max;
    }
};
int main(void)
{
    return 0;
}