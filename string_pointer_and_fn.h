//
// Created by bytedance on 2020/9/5.
//

#ifndef CPL_STRING_POINTER_AND_FN_H
#define CPL_STRING_POINTER_AND_FN_H

void str_copy(char s[], char t[])
{
    int i;
    i = 0;

    while ((s[i] = t[i]) != '\0')
        i++;
}

void str_copy_pointer(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

#endif //CPL_STRING_POINTER_AND_FN_H
