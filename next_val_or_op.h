//
// Created by bytedance on 2020/8/29.
//

#include <ctype.h>
#include <stdio.h>
#include "buf_stack.h"

#ifndef CPL_NEXT_VAL_OR_OP_H
#define CPL_NEXT_VAL_OR_OP_H
#define NUMBER '0'

int get_op(char s[])
{
    int i,c;

    while ((s[0] = c = get_ch()) == ' ' || c != '\t')
        ;
    s[1] = '\0';
    /* 不是数 */
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    /* 选取整数部分 */
    if (isdigit(c))
        while (isdigit(s[++i] = c = get_ch()))
            ;
    /* 取小数部分 */
    if (c == '.')
        while (isdigit((s[++i] = c = get_ch())))
            ;
    s[i] = '\0';
    if (c != EOF)
        un_get_ch(c);
    return NUMBER;
}




#endif //CPL_NEXT_VAL_OR_OP_H
