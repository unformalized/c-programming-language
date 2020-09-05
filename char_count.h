//
// Created by bytedance on 2020/8/22.
//

// CLion 输入EOF有bug，先不做相关内容
#include <stdio.h>

#ifndef CPL_CHAR_COUNT_H
#define CPL_CHAR_COUNT_H

void char_count()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}


#endif //CPL_CHAR_COUNT_H
