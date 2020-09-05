//
// Created by bytedance on 2020/8/29.
//

#ifndef CPL_SWAP_H
#define CPL_SWAP_H

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#endif //CPL_SWAP_H
