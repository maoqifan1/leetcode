#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/**
 * 找出数组中出现出现大约length/2的元素
*/
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) // 利用摩尔投票法
        {
            if (count == 0) // 如果统计为0时，遇到新数就将新数作为统计的数
            {
                res = nums[i];
                count++;
            }
            else
            {
                res == nums[i] ? count++ : count--; // 遇到新的数时如果和当前数相同，统计数+1，否则统计数-1
            }
        }
        return res;
    }
};