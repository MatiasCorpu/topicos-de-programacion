#include "array.h"

void shiftLeftOverwrite(void *current, void *last, size_t sizeElem)
{
    for (void *i = current; i <= last; i += sizeElem)
        memcpy(i, i + sizeElem, sizeElem);
}

void shiftRightWithInsert(void *current, void *last, size_t sizeElem)
{
    for (void *i = last; i >= current; i -= sizeElem)
        memcpy(i + sizeElem, i, sizeElem);
}

void arrayRemoveAllOccurrences(void *arr, int *ce, size_t sizeElem, void *elem, Compare cmp)
{
    void *current = arr;
    void *last = arr + (*ce - 1) * sizeElem;

    while (current <= last)
    {
        if(cmp(current, elem) == 0)
        {
            shiftLeftOverwrite(current, last, sizeElem);
            (*ce)--;
            last -= sizeElem;
        }
        else
            current += sizeElem;
    }
}

void arrayRemoveFirstOccurrence(void *arr, int *ce, size_t sizeElem, void *elem, Compare cmp)
{
    void *last = arr + sizeElem * (*ce - 1);

    while (arr <= last)
    {
        if (cmp(arr, elem) == 0)
            break;

        arr += sizeElem;
    }

    shiftLeftOverwrite(arr, last, sizeElem);

    (*ce)--;
}

void arrayRemoveElementAtPosition(void *arr, int *ce, size_t sizeElem, int pos)
{
    void *current = arr + (pos - 1) * sizeElem;
    void *last = arr + (*ce - 1) * sizeElem;

    shiftLeftOverwrite(current, last, sizeElem);

    (*ce)--;
}

void arrayInsertElementAtPosition(void *arr, int *ce, size_t sizeElem, int cap, void *elem, int pos)
{
    void *current = arr + (pos - 1) * sizeElem;
    void *last = arr + (*ce - 1) * sizeElem;

    shiftRightWithInsert(current, last, sizeElem);

    memcpy(current, elem, sizeElem);

    (*ce)++;
}

int arrayInsertInSortedOrder(void *arr, int *ce, size_t sizeElem, int cap, void *elem, Compare cmp)
{
    if (cap == *ce)
        return ERR_MEM;

    void *curr = arr;
    void *last = arr + sizeElem * (*ce - 1);

    int comp;

    while (curr <= last)
    {
        comp = cmp(elem, curr);

        if (comp < 0)
            break;

        else if (comp == 0)
            return DUPLICATE;

        curr += sizeElem;
    }

    for (void *i = last; i >= curr; i -= sizeElem)
        memcpy(i + sizeElem, i, sizeElem);

    (*ce)++;
    memcpy(curr, elem, sizeElem);

    return ALL_OK;
}

void arrayPrint(void *arr, int ce, size_t sizeElem, Show show)
{
    void *last = arr + sizeElem * (ce - 1);

    for (void *i = arr; i <= last; i += sizeElem)
        show(i);
}

// esto no tendria que ir no es parte de la libreria array:
int cmpInst(void *x, void *y)
{
    return *(int *)x - *(int *)y;
}

void showInt(void *x)
{
    printf("%d ", *(int *)x);
}
