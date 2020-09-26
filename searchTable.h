//
// Created by bytedance on 2020/9/26.
//

#ifndef CPL_SEARCHTABLE_H
#define CPL_SEARCHTABLE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define IN 1
#define HASH_SIZE 101

struct nList {
    struct nList *next;
    char *name;
    char *defn;
};

static struct nList *hashTable[HASH_SIZE];


unsigned hash(char *s) {
    unsigned hash_val;

    for (hash_val = 0; *s != '\0';s++)
        hash_val = *s + 31 * hash_val;
    return hash_val % HASH_SIZE;
}

struct nList *lookup(char *s) {
    struct nList *np;

    for (np = hashTable[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;

    return NULL;
}

struct nList *install(char *name, char *defn) {
    struct nList *np;
    unsigned hash_val;

    if ((np = lookup(name)) != NULL) {
        np = (struct nList *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hash_val = hash(name);
        np->next = hashTable[hash_val];
        hashTable[hash_val] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}


#endif //CPL_SEARCHTABLE_H
