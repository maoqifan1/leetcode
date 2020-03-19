// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

// 示例 :
// 给定二叉树

//           1
//          / \
//         2   3
//        / \     
//       4   5    
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

#include <iostream>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode
{
    int val; // 节点值
    TreeNode *left; // 左子树
    TreeNode *right; // 右子树
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int max_length;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        depthTraverse(root);
        return max_length;
    }
    int depthTraverse(TreeNode *root) //DFS
    {
        if (!root)
            return 0;
        int right = depthTraverse(root->right); // DFS右子树
        int left = depthTraverse(root->left);   // DFS左子树
        if (left + right > max_length)
            max_length = left + right;
        return max(left, right) + 1;
    }
};