#include <iostream>
#include <vector>
using namespace std;
// 排排坐，分糖果。
// 我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。
// 给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。
// 然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。
// 重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。
// 返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。

// 示例 1：

// 输入：candies = 7, num_people = 4
// 输出：[1,2,3,1]
// 解释：
// 第一次，ans[0] += 1，数组变为 [1,0,0,0]。
// 第二次，ans[1] += 2，数组变为 [1,2,0,0]。
// 第三次，ans[2] += 3，数组变为 [1,2,3,0]。
// 第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。


class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> v(num_people, 0); // 初始化向量，长度为小朋友数
        int candy = 0;
        int i = 0;          // 遍历起点
        while (candies > 0) // 当有糖可发时，给小朋友发糖
        {
            if (candies <= candy + i + 1) // 如果糖不够发了，则把所有糖给这个小朋友然后跳出循环
            {
                v.at(i) += candies;
                break;
            }
            v.at(i) += candy + i + 1;       // 给小朋友发的糖递增
            candies -= (candy + (i++) + 1); // 从总糖果里减去发掉的糖
            if (i == v.size())              // 当给最后一个小朋友发完糖后，重新给第一个小孩子发糖，并且发的糖比上一轮多一个
            {
                i = 0;
                candy += num_people; // 下一轮第一次发的糖
            }
        }
        return v; // 返回发完糖的小朋友数组
    } // 运行时间 0 ms ，内存 7.9mB
};
int main(void)
{
    Solution *s = new Solution();
    s->distributeCandies(10, 10);
    return 0;
}