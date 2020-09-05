//
// Created by bytedance on 2020/8/22.
//

#include <stdio.h>

#ifndef CPL_TYPE_TRANSFORMER_H
#define CPL_TYPE_TRANSFORMER_H

void int_long_transformer() {
    long a = 214875382952734;
    int b = (int) a;
    printf("b: %d\n", b);
}

#endif //CPL_TYPE_TRANSFORMER_H
