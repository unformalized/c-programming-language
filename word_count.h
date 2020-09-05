//
// Created by bytedance on 2020/8/22.
//

#include <stdio.h>

#define IN 1
#define OUT 0


#ifndef CPL_WORD_COUNT_H
#define CPL_WORD_COUNT_H

void word_count()
{
    int c,nl,nw,nc,state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("newline count: %d, new_word count: %d, new_char count: %d", nl, nw, nc);
}

#endif //CPL_WORD_COUNT_H
