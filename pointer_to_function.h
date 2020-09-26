//
// Created by bytedance on 2020/9/12.
//

#ifndef CPL_POINTER_TO_FUNCTION_H
#define CPL_POINTER_TO_FUNCTION_H

/* 指向函数的指针 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 5000
char *line_pointer[MAX_LINES];

int readLines(char *line_pointer[], int n_lines);
int writeLines(char *line_pointer[], int n_lines);
void swap(char *v[], int left, int right);

int num_comp(char *, char *);


// 快速排序接受第四个比较函数参数 int (* comp)(void *, void *);
void quick_sort(void *v[], int left, int right,
                int (*comp)(void *, void *))
{
    int i,last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((* comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    quick_sort(v, left, last - 1, comp);
    quick_sort(v, last + 1, right, comp);

}

int sort_input_lines(int argc, char *argv[])
{
    int n_lines;
    int numeric = 0;

    // 如果传入 -n 参数则采用数值进行排序比较
    if (argc > 1 && strcmp(argv[1], '-n') == 0)
        numeric = 1;
    if ((n_lines = readLines(line_pointer, MAX_LINES)) > 0) {
        quick_sort(line_pointer, 0, n_lines - 1,
                   (int (*)(void *, void *))(numeric ? num_comp : strcmp));
        writeLines(line_pointer, MAX_LINES);
        return 1;
    } else {
        printf("error: input too big to sort");
        return 0;
    }
}

int num_cmp(char *s1, char *s2)
{
    double v1,v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 > v2)
        return 1;
    else if (v1 < v2)
        return -1;
    else
        return 0;
}


#endif //CPL_POINTER_TO_FUNCTION_H
