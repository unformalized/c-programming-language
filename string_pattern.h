//
// Created by bytedance on 2020/8/22.
//

#include <stdio.h>

#ifndef CPL_STRING_PATTERN_H
#define CPL_STRING_PATTERN_H

#define MAX_LINE 1000
int get_line(char line[], int max);
int str_index(char source[], char searcher[]);

/* 带查找的模式 */
char pattern[] = "ould";

int string_pattern()
{
    char line[MAX_LINE];
    int found = 0;

    while (get_line(line, MAX_LINE) > 0) {
        if (str_index(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }

    return found;
}

int get_line(char s[], int limit)
{
    int c,i;
    i = 0;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i++] = '\0';
    return i;
}

int str_index(char source[], char searcher[])
{
    int i,j,k;

    for (i = 0; source[i] != '\0'; i++) {
        for (j = i, k =0; searcher[k] != '\0' && source[j] == searcher[k]; j++, k++)
            ;
        if (k > 0 && searcher[k] != '\0')
            return i;
    }
    return -1;
}

#endif //CPL_STRING_PATTERN_H
