//
// Created by bytedance on 2020/8/22.
//

#ifndef CPL_COPY_FILE_H
#define CPL_COPY_FILE_H

#include <stdio.h>

void print_file()
{
    int c;

    c = getchar();
    if (c != EOF) {
        putchar(c);
        c = getchar();
    }
}



#endif //CPL_COPY_FILE_H
