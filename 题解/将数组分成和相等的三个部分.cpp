#include <iostream>
#include <numeric>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {
        int sum = accumulate(A.begin(), A.end(), 0); // 求和
        if (sum % 3 != 0)
            return false;                   // 对三求余等于0表示数组不能被三等分
        int avg = sum / 3;                  // 获得平均数
        int left = 0, right = A.size() - 1; // 获得左右指针
        int left_sum = 0, right_sum = 0;    // 初始化左右和为空
        bool flag = false;                  // 判断是否能计算出左右和相等的情况
        while (left < right)
        { // 当左指针小于右边时继续循环
            if (left_sum != avg)
            { // 若左边的和小于平均数， 向右累加
                left_sum += A.at(left++);
            }
            if (right_sum != avg)
            { // 若右边的和小于平均数， 向左累加
                right_sum += A.at(right--);
            }
            if (left_sum == avg && right_sum == avg)
            { // 如果左右的和都等于平均数, 跳出循环
                flag = true;
                break;
            }
        }
        return flag && right - left > 1; // 当左右和相等且左右指针中间最少有一个空间时，表示该数组能被三等分
    }
};
int main(void){
    Solution *s = new Solution();
    vector<int>v = {3,3,6,5,-2,2,5,1,-9,4};
    bool result = s->canThreePartsEqualSum(v);
    cout<<"该数组"<<(result?"能":"不能")<<"被三等分"<<endl;
}
