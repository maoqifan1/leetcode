#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next; // 指针域
} List;                // 链表定义

void create_list_head(List *&list, int a, int n); // 采用头插法创建链表
void create_list_tail(List *&list, int a, int n); // 采用尾插法创建链表
void sort(List *&list);                           // 对链表进行排序
void visvit(List *list);                          // 输出链表数据

void create_list_head(List *&list, int a[], int n)
{
    list = nullptr; // 清空链表
    List *p;
    for (int i = 0; i < n; ++i)
    {
        p = (List *)malloc(sizeof(List)); // 申请节点内存
        p->data = a[i];
        p->next = list;
        list = p;
    }
    // 链表创建完成
}

void create_list_tail(List *&list, int a[], int n)
{
    list = nullptr; // 清空链表
    List *p;
    for (int i = 0; i < n; ++i)
    {
        p = (List *)malloc(sizeof(List)); // 申请节点空间
        p->data = a[i];
        
        
        
    }
}

void sort(List *&list)
{
    List *p, *q, *r;
    int temp;
    for (p = list; p != nullptr; p = p->next)
    {
        r = p;
        for (q = p->next; q != nullptr; q = q->next)
        {
            if (q->data < r->data) // 找最小值
                r = q;
        }
        if (r != p)
        {
            temp = p->data;
            p->data = r->data;
            r->data = temp;
        }
    }
    // 排序完成
}

void visit(List *list)
{
    List *p = list;
    while (p != nullptr)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
}
int main()
{
    List *root;
    int a[] = {0, 20, 31, 29, 1, 4, 9, 10, 22};
    create_list_head(root, a, 9); // 创建链表
    sort(root);                   // 排序
    visit(root);                  //访问
    return 0;
}