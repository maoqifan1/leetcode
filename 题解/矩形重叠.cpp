// 矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
// 如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
// 给出两个矩形，判断它们是否重叠并返回结果。

// 示例 1：
// 输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
// 输出：true

// 示例 2：
// 输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
// 输出：false
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 根据题意，我们只需要判断矩形不相交的情况，剩下的就是相交的情况
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        // 相交时，第一个矩形右下角的横坐标要大于第二个矩形左下角的横坐标
        // 或者，第一个矩形的右上角纵坐标大于第二个矩形左下角的纵坐标
        // 排除这几种情况就是不相交的情况
        return !(rec1.at(2) <= rec2.at(0) || rec2.at(2) <= rec1.at(0) || rec1.at(3) <= rec2.at(1) || rec2.at(3) <= rec1.at(1));
    }
};