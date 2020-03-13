#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    /**
     * 方法1，递归实现(较为简单)
    */
    vector<int> inorderTraversalRecursive(TreeNode *root)
    {
        vector<int> v;
        inorderTraversalRecursive(root->left);  // 递归遍历左子树
        v.push_back(root->val);                 // 访问根节点
        inorderTraversalRecursive(root->right); // 递归遍历右子树
        return v;                               // 返回遍历序列
    }
    /**
     * 方法2，非递归实现(使用栈进行实现)
    */
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v; // 创建向量
        if (!root)     // 若根节点为空，返回空向量
            return v;
        stack<TreeNode> s;            // 创建栈
        while (s.size() != 0 || root) // 只要栈不为空或者节点不为空，则进行迭代
        {
            while (root) // 根节点不为空
            {
                s.push(*(root));   // 根结点入栈
                root = root->left; //访问左子树
            }
            //否则，获取栈顶节点访问后弹出
            root = &s.top();
            cout << root->val;
            v.push_back(root->val);
            s.pop();
            // 访问被弹出节点(根)的右子树
            root = root->right;
        }
        return v;
    }
};