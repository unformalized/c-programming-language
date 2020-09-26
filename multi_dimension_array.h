//
// Created by bytedance on 2020/9/12.
//

#ifndef CPL_MULTI_DIMENSION_ARRAY_H
#define CPL_MULTI_DIMENSION_ARRAY_H

// 多维数组

static char dayTab[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
};


int day_of_year(int year, int month, int day) {
    int i,leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 != 0;
    for (i = 0; i < month; ++i) {
        day += dayTab[leap][i];
    }
    return day;
}

#endif //CPL_MULTI_DIMENSION_ARRAY_H
