//
// Created by bytedance on 2020/8/22.
//

#include <stdio.h>

#ifndef CPL_ALL_COUNT_BY_ARR_H
#define CPL_ALL_COUNT_BY_ARR_H

void all_count()
{
    int c, i, n_white, n_other;
    int n_digit[10];

    n_white = n_other = 0;
    for ( i = 0; i < 10; ++i)
        n_digit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++n_digit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++n_white;
        else
            ++n_other;

    printf("digit =");
    for (i = 0; i < 10; ++i)
        printf(" %d", n_digit[i]);

    printf(", n_white space = %d, n_other: %d", n_white, n_other);
}

#endif //CPL_ALL_COUNT_BY_ARR_H
