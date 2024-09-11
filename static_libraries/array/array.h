#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALL_OK 0
#define DUPLICATE 1
#define ERR_MEM 2

typedef int (*Compare)(void *, void *);
typedef void (*Show)(void *);

int cmpInst(void *x, void *y);
void showInt(void *x);

void shiftLeftOverwrite(void *current, void *last, size_t sizeElem);
void shiftRightWithInsert(void *current, void *last, size_t sizeElem);

void arrayPrint(void *arr, int ce, size_t sizeElem, Show show);

void arrayInsertElementAtPosition(void *arr, int *ce, size_t sizeElem, int cap, void *elem, int pos);
int arrayInsertInSortedOrder(void *arr, int *ce, size_t sizeElem, int cap, void *elem, Compare cmp);
void arrayRemoveElementAtPosition(void *arr, int *ce, size_t sizeElem, int pos);
void arrayRemoveFirstOccurrence(void *arr, int *ce, size_t sizeElem, void *elem, Compare cmp);
void arrayRemoveAllOccurrences(void *arr, int *ce, size_t sizeElem, void *elem, Compare cmp);

#endif // ARRAY_H_INCLUDED
