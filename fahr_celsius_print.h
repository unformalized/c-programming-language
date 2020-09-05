//
// Created by bytedance on 2020/8/22.
//

#include <stdio.h>

// 符号常量
#define MAX 300
#define STEP 10

#ifndef CPL_FAHR_CELSIUS_PRINT_H
#define CPL_FAHR_CELSIUS_PRINT_H

void fahr_celsius_print() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 30;

    fahr = lower;
    while (fahr <= MAX) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}

#endif //CPL_FAHR_CELSIUS_PRINT_H
