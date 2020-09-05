//
// Created by bytedance on 2020/8/29.
//

#include <stdio.h>
#define BUF_SIZE 100

#ifndef CPL_BUF_STACK_H
#define CPL_BUF_STACK_H

static char buf[BUF_SIZE];
static int buf_p = 0;

int get_ch(void)
{
    return (buf_p > 0) ? buf[--buf_p] : getchar();
}

void un_get_ch(int c)
{
    if (buf_p > BUF_SIZE)
        printf("un_get_ch: too many characters\n");
    else
        buf[++buf_p] = c;
}

#endif //CPL_BUF_STACK_H
