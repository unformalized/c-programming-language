//
// Created by bytedance on 2020/8/29.
//
#include <stdio.h>

#define MAX_VAL 100


#ifndef CPL_OP_STACK_H
#define CPL_OP_STACK_H

int sp = 0;
double val[MAX_VAL];

void push(double f)
{
    if (sp > MAX_VAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty, can't pop \n");
        return 0.0;
    }

}


#endif //CPL_OP_STACK_H
