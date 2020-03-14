#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#define ROWS 4
#define COLS 4
using namespace std;

static int triangle[ROWS][COLS] = {
    {2, 0, 0, 0},
    {3, 4, 0, 0},
    {6, 5, 7, 0},
    {4, 1, 8, 3}};          // 要求解的三角形
static map<string, int> mp; // 缓存已知路径
// 递归解法
int traverseRecursive(int i, int j)
{
    string key = to_string(i) + to_string(j);
    if (mp.find(key) != mp.end())
        return mp.find(key)->second; //若该路径已被缓存则直接返回
    if (i >= ROWS - 1)               // base case 如果当i将要越界时 返回0
        return 0;
    int left = traverseRecursive(i + 1, j) + triangle[i + 1][j];          // 往左下
    int right = traverseRecursive(i + 1, j + 1) + triangle[i + 1][j + 1]; // 往右下
    int min_path = min(left, right);                                      // 取最小的路径
    mp.insert(pair<string, int>(key, min_path));                          //缓存
    return min_path;
}
// 动态规划解法
int traverse()
{
    int *p = triangle[ROWS - 1];        // 取三角形最后一行
    for (int i = ROWS - 2; i >= 0; i--) // 从倒数第二行开始遍历
    {
        for (int j = 0; j < COLS; j++) // 遍历每一列
        {
            if (triangle[i][j] == 0) // 如果是0则直接跳过
                continue;
            p[j] = triangle[i][j] + min(p[j], p[j + 1]); // 取到这个节点权重最小的节点
        }
    }
    return p[0];
}
int main(void)
{
    int n = traverse(); // 从一个节点出发
    printf("最小路径和为: %d", n);
}