#include <iostream>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild, *parent;
} BTNode, BST;

void insertNode(BST *&root, int e);         // root 表示二叉搜索树的树根,e表示待插入节点的值
void createBST(BST *&root, int a[], int n); // root 表示二叉搜索树，a表示代插入节点数组，n为数组长度
void inorder_trave(BST *root);              // 中序遍历二叉搜索树
BST *bst_search(BST *root, int e);          // 搜索指定值的节点，并返回该节点的指针
void match_parent(BST *&root, BST *&pre);   // 给树中的parent指针赋值

void createBST(BST *&root, int a[], int n)
{
    root = nullptr; // 根赋值为空
    for (int i = 0; i < n; i++)
    {
        insertNode(root, a[i]);
    }
    // 程序结束
}

void insertNode(BST *&root, int e)
{
    if (root == nullptr)
    {
        BST *p = (BST *)malloc(sizeof(BST));         // 创建新节点
        p->data = e;                                 // 赋值
        p->lchild = p->rchild = p->parent = nullptr; // 左右孩子为空,父亲指针也赋值为空
        root = p;                                    // 赋值给root
    }
    else if (root->data == e)
        return;
    else
    {
        insertNode(root->data > e ? root->lchild : root->rchild, e); // 递归插入
    }
}

void inorder_trave(BST *root)
{
    if (root != nullptr)
    {
        inorder_trave(root->lchild);
        printf("%d -> ", root->data);
        inorder_trave(root->rchild);
    }
}

BST *bst_search(BST *root, int e)
{
    if (root == nullptr) // 空树，返回空指针
        return root;
    if (root->data == e)
        return root;
    return bst_search(root->data > e ? root->lchild : root->rchild, e); // 递归搜索
}

void match_parent(BST *&root, BST *&pre);   // 给树中的parent指针赋值


int main()
{
    BST *root; // 创建一个根
    int a[] = {1, 2, 8, 10, 31, 35, 19, 70, 29};
    createBST(root, a, 9); // 创建二叉搜索树
    inorder_trave(root);   // 遍历该树
    BST *p = bst_search(root, 2);
    free(p);
    free(root);
}