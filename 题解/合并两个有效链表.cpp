// 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
// 示例：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2) // 如果两个链表都是空的，直接返回链表
            return l1;
        vector<int> v;                 // 创建向量
        ListNode *p = new ListNode(0); // 创建链表
        while (l1)                     // 当链表l1非空时，循环遍历
        {
            v.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) // 当链表l2非空时循环遍历
        {
            v.push_back(l2->val);
            l2 = l2->next;
        }
        sort(v.begin(), v.end());          // 对数组排序
        ListNode *q = p;                   // 指针q指向p
        for (int i = 0; i < v.size(); i++) // 循环创建链表
        {
            p->val = v[i];
            if (i < v.size() - 1)
                p->next = new ListNode(NULL);
            p = p->next;
        }
        return q; // 返回归并后的链表
    }
};