//
// Created by bytedance on 2020/9/5.
//

#ifndef CPL_POINTER_ARRAY_H
#define CPL_POINTER_ARRAY_H

// 指针数组及指向指针的指针

#include <stdio.h>
#include <string.h>

#define MAX_LINES 5000

char *line_ptr[MAX_LINES];

int readLines(char *line_ptr[], int max_lines);
void writeLines(char *line_ptr[], int n_lines);
void quick_sort(char *v[], int left, int right);
void swap(char *v[], int left, int right);

void sort_input_line()
{
    int nLines;

    if ((nLines = readLines(line_ptr, MAX_LINES)) >= 0) {
        quick_sort(line_ptr, 0, nLines - 1);
        writeLines(line_ptr, nLines);
        return;
    } else {
        printf("error: input too big to arr\n");
        return;
    }
}

#define MAX_LEN 1000
int get_line(char *,int);
char *alloc(int);

int readLines(char *line_ptr[], int max_lines)
{
    int len,n_lines;
    char *p, line[MAX_LEN];

    n_lines = 0;

    while ((len = get_line(line, MAX_LEN)) > 0) {
        if (n_lines >= max_lines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            line_ptr[n_lines++] = p;
        }
    }
    return n_lines;
}

void writeLines(char *line_ptr[], int n_lines) {
    int i;

    for (i = 0; i < n_lines; i++) {
        printf("%s\n", line_ptr[i]);
    }
}

void quick_sort(char *v[], int left, int right)
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

void swap(char *v[], int left, int right)
{
    char *temp;

    temp = v[left];
    v[left] = v[right];
    v[right] = temp;
}

#endif //CPL_POINTER_ARRAY_H
