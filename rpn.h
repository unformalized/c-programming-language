//
// Created by bytedance on 2020/8/25.
//

/**
 * 使用 extern 访问其他文件变量
 * 使用 static 阻止其他文件访问该变量
 * 使用 register 声明为寄存器变量，使程序运行更快
 * */

// 逆波兰求值器

#include <stdio.h>
#include <stdlib.h>
#include "op_stack.h"

#define MAX_OP_LEN 100

int get_op(char []);

#ifndef CPL_RPN_H
#define CPL_RPN_H
#define NUMBER '0'

int rpn()
{
    int type;
    double op2;
    char s[MAX_OP_LEN];

    while ((type = get_op(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: Unknown command %s\n", s);
                break;
        }
    }
    return 0;
}


#endif //CPL_RPN_H
