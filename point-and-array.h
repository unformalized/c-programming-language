//
// Created by bytedance on 2020/9/5.
//

#ifndef CPL_POINT_AND_ARRAY_H
#define CPL_POINT_AND_ARRAY_H


#include <stdio.h>
/*
 * 指针是能够存储一个地址的一组存储单元（两个字节或四个字节）
 * 一元运算符 & 用于取一个对象的地址  p = &c;
 * * ** 地址运算符 & 只能应用于内存中的对象，即变量和数组元素，不能用于表达式，常量和register类型变量
 * 一元运算符 * 是间接寻址或间接引用运算符
 * 当它作用于指针时，将访问指针指向的对象
 *
 *
 * & 和 * 的优先级比算术运算符高
 *
 * int *px 定义指针类型， &px 访问一个变量的地址
 * *(&px)
 * */


void pointer()
{
    int x = 1, y = 2, z[10];
    /* ip 是指向 int 类型的指针 */
    int *ip;

    /* ip 指向 x */
    ip = &x;

    /* y = 1 */
    y = *ip;
    /* x = 0 */
    *ip = 0;

    printf( "x: %d, y: %d", x, y);
    ip = &z[0];
}

void pointer_arg_fn()
{

}

/* swap 错误定义，无法达到要求 */
void swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void swap_with_pointer(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

/*
 * *s 是指针类型
 * s 是地址, s + 1是下一个地址
 *
 * */
int str_len(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;

    return n;
}




#endif //CPL_POINT_AND_ARRAY_H
