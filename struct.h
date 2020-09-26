//
// Created by bytedance on 2020/9/12.
//

#ifndef CPL_STRUCT_H
#define CPL_STRUCT_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "buf_stack.h"



// 第六章 结构

struct point {
    int x;
    int y;
};

struct point max_pt = {
    320,
    200,
};

struct point makePoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

// 结构指针
struct point *pp;

void struct_and_function()
{
    struct point origin = {
        100, 200
    };

    pp = &origin;
    printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
    printf("origin is (%d,%d)\n", pp->x, pp->y);
}


// 结构运算符 . 和 -> ，函数调用 (), 用于下标的 [] 这四个运算符优先级最高

// 结构数组

struct key {
    char *word;
    int count;
};

void struct_and_array()
{
    struct key keyTab[1] = {
        "auto", 0
    };

}


struct key keyTab[] = {
    "auto", 0,
    "break", 0
};

// 单词统计程序

#define MAX_WORD 100
#define MAX_KEYS ((sizeof keyTab) / (sizeof keyTab[0]))



int get_word(char *, int);
int binarySearch(char *, struct key *, int);

int wordCounter()
{
    int n;
    char word[MAX_WORD];

    while (get_word(word, MAX_WORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binarySearch(word, keyTab, MAX_KEYS)) >= 0)
                keyTab[n].count++;
    for (n = 0; n < MAX_KEYS; ++n) {
        if (keyTab[n].count > 0)
            printf("%4d %s\n",
                   keyTab[n].count, keyTab[n].word);
    }
    return 0;
}

int binarySearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond >  0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}


int get_word(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = get_ch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = get_ch())) {
            un_get_ch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

// 自引用结构

struct treeNode {
    char *word;
    int count;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *addTree(struct treeNode *, char *);
void treePrint(struct treeNode *);

int wordCountByTree()
{
    struct treeNode *root;
    char word[MAX_WORD];

    root = NULL;
    while (get_word(word, MAX_WORD) != EOF)
        if (!isalpha(word[0]))
            root = addTree(root, word);
    treePrint(root);
    return 0;
}

struct treeNode *treeAlloc(void);
char *strDup(char *);


struct treeNode *addTree(struct treeNode *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = treeAlloc();
        p->word = strDup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addTree(p->left, w);
    else
        p->right = addTree(p->right, w);
    return p;
}

void treePrint(struct treeNode *root)
{
    if (root != NULL) {
        treePrint(root->left);
        printf("tree words: %s", root->word);
        treePrint(root->right);
    }
}

// 实现 treeAlloc内存分配函数
struct treeNode *treeAlloc(void)
{
    return (struct treeNode *) malloc(sizeof(struct treeNode));
}

// 实现 strDup 复制到一个安全的地方
char *strDup(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

#endif //CPL_STRUCT_H
