//
// Created by bytedance on 2020/9/5.
//

#ifndef CPL_ADDRESS_ARITHMETIC_H
#define CPL_ADDRESS_ARITHMETIC_H

// 地址算术运算

#define ALLOC_SIZE 10000

static char alloc_buf[ALLOC_SIZE];
static char *alloc_p = alloc_buf;


/* 获取大小为 n 的字符空间，并返回空间中第一个位置的地址 */
char *alloc(int n)
{
    /* 存在足够的空间 */
    if (alloc_buf + ALLOC_SIZE - alloc_p >= n) {
        alloc_p += n;
        return alloc_p - n;
    } else
        return 0;
}

/* 释放 p 占用的空间 */
void afree(char *p)
{
    if (p > alloc_buf && p < alloc_buf + ALLOC_SIZE)
        alloc_p = p;
}


#endif //CPL_ADDRESS_ARITHMETIC_H
