//
// Created by bytedance on 2020/8/22.
//
#include "lib.h"

#define MAX_LINE 1000

// 外部变量
int max;
char line[MAX_LINE];
char longest[MAX_LINE];


int get_line(char s[], int limit);
void copy(char to[], char from[]);

#ifndef CPL_PRINT_LONGEST_LINE_H
#define CPL_PRINT_LONGEST_LINE_H

int print_longest_line() {
    int len;
    max = 0;

    while ((len = get_line(line, MAX_LINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("%s", longest);

    return 0;
}

/* get_line 函数：将一行字符串读入到 s 中，并返回长度 */
int get_line(char s[], int limit)
{
    int c,i;

    for (int i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy 函数：将 from 复制到 to ; */
void copy(char to[], char from[])
{
    int i;
    i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}


#endif //CPL_PRINT_LONGEST_LINE_H
