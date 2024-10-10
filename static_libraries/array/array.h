#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALL_OK 0
#define DUPLICATE 1
#define ERR_MEM 2

typedef int (*Compare)(const void *, const void *);
typedef void (*Show)(void *);

// typedef void (*Action)(void *, void *); // hacer que esta abarque todas las funciones y sacar Compare

void showInt(void *x);
int cmpInst(const void *x, const void *y);

void arrayPrint(void *arr, int ce, size_t sizeElem, Show show);
void shiftLeftOverwrite(void *current, void *last, size_t sizeElem);
void shiftRightWithInsert(void *current, void *last, size_t sizeElem);
void arrayInsertElementAtPosition(void *arr, int *ce, size_t sizeElem, int cap, void *elem, int pos);
int arrayInsertInSortedOrder(void *arr, int *ce, size_t sizeElem, int cap, void *elem, Compare cmp);
void arrayRemoveElementAtPosition(void *arr, int *ce, size_t sizeElem, int pos);
void arrayRemoveFirstOccurrence(void *arr, int *ce, size_t sizeElem, void *elem, Compare cmp);
void arrayRemoveAllOccurrences(void *arr, int *ce, size_t sizeElem, void *elem, Compare cmp);

//void arrayForEach(void *arr, int ce, size_t sizeElem, Action action, void *dataAction); // hacer que esta abarque todas las funciones y sacar Compare

double averageOfPairs(void *arr, int ce, size_t sizeElem);
void arrayPrintReverse(void *arr, int ce, size_t sizeElem, Show show);
void sumOfAllElements(void *arr, int ce, size_t sizeElem, void *sum);
void *searchMin(void *arr, int ce, size_t sizeElem, Compare cmp);
void *searchElement(void *arr, int ce, size_t sizeElem, void *elem, Compare cmp);
void *binarySearch(void *arr, int ce, size_t sizeElem, void *elem, Compare cmp);
void sortInsertion(void *arr, int ce, size_t sizeElem, Compare cmp);
void sortSelection(void *arr, int ce, size_t sizeElem, Compare cmp);
void swap(void *a, void *b, size_t sizeElem);

#endif // ARRAY_H_INCLUDED
