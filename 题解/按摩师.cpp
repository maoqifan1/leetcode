// 一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
// 给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
// 示例 1：

// 输入： [1,2,3,1]
// 输出： 4
// 解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
// 示例 2：

// 输入： [2,7,9,3,1]
// 输出： 12
// 解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
// 示例 3：

// 输入： [2,1,4,5,3,1,1,3]
// 输出： 12
// 解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int massage1(vector<int> &nums) // o(n) 空间复杂度
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return nums.at(0);
        int dp[nums.size()]; // 创建DP数组
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]); // 从nums数组的前两个元素中找出最大值
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]); // 递推公式
        }
        return dp[nums.size() - 1]; // 返回最后一个元素，这个元素一定是总时长最大的
    }
    int message2(vector<int> &nums) // o(1) 空间复杂度
    {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        return b;
    }
};