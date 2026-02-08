#ifndef TDA_VECTOR_H_INCLUDED
#define TDA_VECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define OK 0
#define DUPLICATE 1

typedef int (*Compare)(const void *, const void *);

typedef struct
{
    void *array;
    int size;
    size_t sizeElement;
    int capacity;
} Vector;

void *vectorCreate(Vector *v, int cap, size_t sizeElement);
bool vectorResize(Vector *v);
void vectorDestroy(Vector *v);
bool vectorIsFull(Vector *v);
bool vectorIsEmpty(Vector *v);
int vectorInsertOrdered(Vector *v, void *data, Compare cmp);
void vectorUnshift(Vector *v, void *data, void *pos);
void vectorInsertAtPosition(Vector *v, void *data, int pos);
void vectorPush(Vector *v, void *data);
void vectorShift(Vector *v, void *pos);
void vectorDeleteAtPosition(Vector *v, int pos);
void vectorDeleteElement(Vector *v, void *data, Compare cmp);
void vectorDeleteElementAll(Vector *v, void *data, Compare cmp);
void vectorClear(Vector *v);
void vectorPop(Vector *v);
void vectorSortInsertion(Vector *v, Compare cmp);
void vectorSortSelection(Vector *v, Compare cmp);
void *vectorMax(Vector *v, Compare cmp, void *iniPos);
void *vectorMin(Vector *v, Compare cmp, void *iniPos);
void *vectorSearch(Vector *v, void *data, Compare cmp);
void *vectorBinarySearch(Vector *v, void *data, Compare cmp);
void vectorSwap(Vector *v, int pos1, int pos2);
void *vectorGet(Vector *v, int pos);
void *vectorGetFirst(Vector *v);
void *vectorGetLast(Vector *v);
void vectorConcat(Vector *v1, Vector *v2);
void vectorSet(Vector *v, void *data, int pos);
void vectorReverse(Vector *v);

#endif // TDA_VECTOR_H_INCLUDED
