#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int a[], int low, int high) // 快速排序
{
    int i, j, pivot;
    i = low;
    j = high;
    if (low < high)
    {
        pivot = a[low];
        while (i < j)
        {
            while (j > i && a[j] > pivot)
                --j;
            if (j > i)
            {
                a[i] = a[j];
                ++i;
            }

            while (i < j && a[i] < pivot)
                ++i;
            if (i < j)
            {
                a[j] = a[i];
                --j;
            }
        }
        a[i] = pivot;          // 一趟排序完成
        quick_sort(a, low, i); // 递归
        quick_sort(a, i + 1, high);
    }
}

void select_sort(int a[], int n) // 选择排序
{
    int min, temp;
    for (int i = 0; i < n; ++i)
    {
        min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int main()
{
    int a[] = {10, 20, 1, 9, 50, 30, 18, 70, 0, 99};
    // quick_sort(a, 0, 9);
    select_sort(a, 10);
    for (int i = 0; i < 10; ++i)
        printf("%d\t", a[i]);
}