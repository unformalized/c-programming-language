//
// Created by bytedance on 2020/8/29.
//

#include "swap.h"

#ifndef CPL_QUICK_SORT_H
#define CPL_QUICK_SORT_H

void quick_sort(int v[], int left, int right)
{
    int i,last;


    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    quick_sort(v, left, last - 1);
    quick_sort(v, last + 1, right);
}

#endif //CPL_QUICK_SORT_H
