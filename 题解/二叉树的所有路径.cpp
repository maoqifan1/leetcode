/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    // 深度优先遍历，获得路径
    // 子程序
    void getPath(TreeNode *root, vector<string> &res, string path)
    {
        path += to_string(root->val); // 获得树根的值并转化为字符串

        if (root->left == nullptr && root->right == nullptr) // 如果当前节点是树叶节点，则把根节点到当前的路径加入到结果集中
        {
            res.push_back(path);
            return; // 结束此次递归
        }

        if (root->left)
            getPath(root->left, res, path + "->"); // 递归
        if (root->right)
            getPath(root->right, res, path + "->");
    }
    // 主程序
    vector<string> getAllPaths(TreeNode *root)
    {
        vector<string> res;
        if (root == nullptr)
            return res; // 树为空返回空集合

        getPath(root, res, ""); //深度优先遍历，修改结果集
        return res;
    }
};